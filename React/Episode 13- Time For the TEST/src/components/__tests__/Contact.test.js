import { render, screen } from "@testing-library/react";
import Contact from "../Contact";
import "@testing-library/jest-dom";

// Describe Block used for grouping test cases.
// Unit Testing:
describe("Contact Us Page Test Cases", () => {
    // // Runs before running any test cases.
    // beforeAll(() => {
    //     console.log("Before All");
    // });
    // // Runs after running any test cases.
    // afterAll(() => {
    //     console.log("After All");
    // });

    // // Runs Before each Test cases.
    // beforeEach(() => {
    //     console.log("Before Each");
    // });
    // // Runs After each Test cases.
    // afterEach(() => {
    //     console.log("After Each");
    // });

    test("Should load contact us component", () => {
        // Render it to JSDOM
        render(<Contact />);

        const heading = screen.getByRole("heading");

        // Assertion
        expect(heading).toBeInTheDocument();
    });

    test("Should load button inside contact component", () => {
        // Render it to JSDOM
        render(<Contact />);

        // const button = screen.getByRole("button");
        const button = screen.getByText("Submit");

        // Assertion
        expect(button).toBeInTheDocument();
    });

    // it and test is same thing
    it("Should load input name inside contact component", () => {
        // Render it to JSDOM
        render(<Contact />);

        // const button = screen.getByRole("button");
        const placeholder = screen.getByPlaceholderText("name");

        // Assertion
        expect(placeholder).toBeInTheDocument();
    });

    it("Should load 2 input boxes inside contact component", () => {
        // Render it to JSDOM
        render(<Contact />);

        // Querying
        // Multiple Items: All
        const inputBoxes = screen.getAllByRole("textbox");

        // This is a JSX element ARRAY
        // console.log(inputBoxes);

        // Assertion
        expect(inputBoxes.length).toBe(2);
    });
});
