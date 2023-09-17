import { render, screen } from "@testing-library/react";
import RestaurantCard, { withPromotedLabel } from "../RestuarantCard";
import MOCK_DATA from "../mocks/resCardMock.json";
import MOCK_DATA_PROMOTED from "../mocks/resCardWithPromotedMock.json";
import "@testing-library/jest-dom";

it("Should Render RestaurantCard component with props Data", () => {
    // To Handle Props we need to add mock data
    render(<RestaurantCard resData={MOCK_DATA} />);

    const name = screen.getByText("KFC");

    expect(name).toBeInTheDocument();
});

it("Should Render RestaurantCard component with Promoted Label", () => {

    // For Promoted Label-
    const RestaurantCardPromoted = withPromotedLabel(RestaurantCard);

    // To Handle Props we need to add mock data-
    render(<RestaurantCardPromoted resData={MOCK_DATA_PROMOTED} />);

    const label = screen.getByText("Promoted");
    // console.log(label);

    expect(label).toBeInTheDocument();
});
