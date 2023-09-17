import { fireEvent, render, screen } from "@testing-library/react";
import Body from "../Body";
import { act } from "react-dom/test-utils";
import MOCK_DATA from "../mocks/mockResListData.json";
import { BrowserRouter } from "react-router-dom";
import "@testing-library/jest-dom";

// Fake an API Call--
// To Create a MOCK Fetch Function-
global.fetch = jest.fn(() => {
    // Returns a Promise
    return Promise.resolve({
        // This Promise Returns us a JSON
        json: () => {
            // Again Promise is returned as DATA
            return Promise.resolve(MOCK_DATA);
        },
    });
});

// Integration Testing--
it("should Search Res List for kfc text input", async () => {
    // Whenever their is a change in state variable we need to wrap it inside act().
    await act(async () => {
        // Tests cannot make API Calls thus we need mock function for fetching.
        render(
            // To recognize <LINK/>
            <BrowserRouter>
                <Body />
            </BrowserRouter>
        );
    });

    // Replication of the Flow of Assertions--

    const cardsBeforeSearch = screen.getAllByTestId("resCard");
    expect(cardsBeforeSearch.length).toBe(20);

    const searchBtn = screen.getByRole("button", { name: "Search" });
    // console.log(searchBtn);

    const searchInput = screen.getByTestId("searchInput");
    // console.log(searchInput);

    fireEvent.change(searchInput, { target: { value: "kfc" } });
    fireEvent.click(searchBtn);

    // Assert : Screen should Load 4 res Cards
    const cardsAfterSearch = screen.getAllByTestId("resCard");
    // console.log(cards);

    expect(cardsAfterSearch.length).toBe(1);
});

it("Should Filter Top Rated Restaurant", async () => {
    await act(async () => {
        render(
            <BrowserRouter>
                <Body />
            </BrowserRouter>
        );
    });

    const cardsBefore = screen.getAllByTestId("resCard");
    expect(cardsBefore.length).toBe(20);

    const filterButton = screen.getByRole("button", {
        name: "Top Rated Restaurant",
    });

    fireEvent.click(filterButton);

    const cardsAfter = screen.getAllByTestId("resCard");

    expect(cardsAfter.length).toBe(11);
});
