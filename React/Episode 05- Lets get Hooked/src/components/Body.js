import RestaurantCard from "./RestuarantCard";
import resList from "../utils/mockData";
import { useState } from "react";

// Body Container--
const Body = () => {
    // Local State Variable -  Super Powerful Variable
    // List and function to update--
    // When setListOfRestaurants is called React starts its reconciliation algorithm, re-render the page.
    const [listOfRestaurants, setListOfRestaurants] = useState(resList);
    const [searchText, setSearchText] = useState("");

    // Above Line is same as (Array Destructuring)--
    // const arr = useState(resList);
    // const [listOfRestaurants, setListOfRestaurants] = arr;
    // const listOfRestaurants = arr[0];
    // const setListOfRestaurants = arr[1];

    return (
        <div className="body">
            <div className="search">
                <input
                    type="text"
                    placeholder="Search Restaurant"
                    value={searchText}
                    onChange={(txt) => {
                        console.log(txt.target.value);
                        setSearchText(txt.target.value);
                    }}
                ></input>
                <button
                    className="search-btn"
                    onClick={() => {
                        // Filter Logic--
                        const searchedRestaurant = listOfRestaurants.filter(
                            (res) => {
                                return (
                                    res.info.name.toLowerCase() ===
                                    searchText.toLowerCase()
                                );
                            }
                        );

                        // console.log(searchedRestaurant.length);

                        // Update List--
                        setListOfRestaurants(searchedRestaurant);
                    }}
                >
                    Search
                </button>
            </div>

            <div className="filter">
                <button
                    className="filter-btn"
                    onClick={() => {
                        // Filter Logic Here!
                        const filteredList = listOfRestaurants.filter((res) => {
                            return res.info.avgRating > 4;
                        });
                        // Update List--
                        setListOfRestaurants(filteredList);
                        console.log("button Clicked!");
                    }}
                >
                    Top Rated Restaurant
                </button>
            </div>

            <div className="restaurant-container">
                {/* Iterate Over Each Element with Map function of JS */}
                {listOfRestaurants.map((restaurant) => (
                    <RestaurantCard
                        // Key is important to prevent re-rendering of all the entries previously rendered.
                        // Key needs to be unique Id or indexes in worst case.
                        key={restaurant.info.id}
                        resData={restaurant}
                    />
                ))}
            </div>
        </div>
    );
};

export default Body;
