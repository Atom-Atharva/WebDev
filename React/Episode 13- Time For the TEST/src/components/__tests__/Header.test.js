import { fireEvent, render, screen } from "@testing-library/react";
import Header from "../Header";
import { Provider } from "react-redux";
import appStore from "../../utils/appStore";
import "@testing-library/jest-dom";

// As Link Component in Router is not understandable to testing library.
import { BrowserRouter } from "react-router-dom";

it("Should render Header Component with Login Button", () => {
    // We need to provide store to header component for REDUX
    render(
        <BrowserRouter>
            <Provider store={appStore}>
                <Header />
            </Provider>
        </BrowserRouter>
    );

    const loginButton = screen.getByRole("button", { name: "Login" });
    // const loginButton = screen.getByText("Login");

    expect(loginButton).toBeInTheDocument();
});

it("Should change Login Button to Logout on Click", () => {
    // We need to provide store to header component for REDUX
    render(
        <BrowserRouter>
            <Provider store={appStore}>
                <Header />
            </Provider>
        </BrowserRouter>
    );

    const loginButton = screen.getByRole("button", { name: "Login" });
    // To Do Something
    fireEvent.click(loginButton);

    const logoutButton = screen.getByRole("button", { name: "Logout" });
    expect(logoutButton).toBeInTheDocument();
});

it("Should render Header Component with Cart Items 0", () => {
    // We need to provide store to header component for REDUX
    render(
        <BrowserRouter>
            <Provider store={appStore}>
                <Header />
            </Provider>
        </BrowserRouter>
    );

    const cartItems = screen.getByText("Cart - (0 Items)");

    expect(cartItems).toBeInTheDocument();
});

it("Should render Header Component with Cart Item", () => {
    // We need to provide store to header component for REDUX
    render(
        <BrowserRouter>
            <Provider store={appStore}>
                <Header />
            </Provider>
        </BrowserRouter>
    );

    // Regex : Matching certain parts of the string.
    const cartItems = screen.getByText(/Cart/);

    expect(cartItems).toBeInTheDocument();
});
