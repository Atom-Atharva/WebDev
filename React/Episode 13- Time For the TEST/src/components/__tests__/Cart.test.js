import { act } from "react-dom/test-utils";
import { fireEvent, render, screen } from "@testing-library/react";
import RestaurantMenu from "../RestaurantMenu";
import MOCK_DATA from "../mocks/mockResMenu.json";
import { Provider } from "react-redux";
import appStore from "../../utils/appStore";
import Header from "../Header";
import { BrowserRouter } from "react-router-dom";
import "@testing-library/jest-dom";
import Cart from "../Cart";

global.fetch = jest.fn(() => {
    return Promise.resolve({
        json: () => {
            return Promise.resolve(MOCK_DATA);
        },
    });
});

// Integrated Testing (Cart Flow)
it("Should Load Restaurant Menu Component", async () => {
    await act(async () => {
        render(
            <BrowserRouter>
                <Provider store={appStore}>
                    <Header />
                    <RestaurantMenu />
                    <Cart />
                </Provider>
            </BrowserRouter>
        );
    });

    // Find DOUBLE DOWN accordion and click it--
    const accordionHeader = screen.getByText("DOUBLE DOWN (5)");
    fireEvent.click(accordionHeader);

    // Find Food Items List--
    const foodItems = screen.getAllByTestId("foodItems");
    expect(foodItems.length).toBe(5);

    // Click on First Add Button 2 Times--
    const addBtns = screen.getAllByRole("button", { name: "+ Add" });
    fireEvent.click(addBtns[0]);
    fireEvent.click(addBtns[0]);

    // Check Updated Header--
    const cart = screen.getByText("Cart - (2 Items)");
    expect(cart).toBeInTheDocument();

    // Check Cart Page Content--
    expect(screen.getAllByTestId("foodItems").length).toBe(7);

    // Click Clear Cart
    fireEvent.click(screen.getByRole("button", { name: "Clear Cart" }));

    // Check Cart Page Content--
    expect(screen.getAllByTestId("foodItems").length).toBe(5);

    // Check empty
    expect(
        screen.getByText("Cart is Empty! Add Items to the cart.")
    ).toBeInTheDocument();
});
