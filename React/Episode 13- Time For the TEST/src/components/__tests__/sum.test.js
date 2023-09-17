import { sum } from "../sum";

// Writing test case

// Test Function with description string and callback function--
test("Sum Function should calculate the sum of Two Numbers", () => {
    const result = sum(3, 4);

    // Assertion
    expect(result).toBe(7);
});
