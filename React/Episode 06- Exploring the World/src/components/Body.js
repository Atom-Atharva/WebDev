import RestaurantCard from "./RestuarantCard";
// import resList from "../utils/mockData";
import { useState, useEffect } from "react";
import Shimmer from "./Shimmer";

// Body Container--
const Body = () => {
    // Local State Variable -  Super Powerful Variable
    // List and function to update--
    // When setListOfRestaurants is called React starts its reconciliation algorithm, re-render the page.
    const [listOfRestaurants, setListOfRestaurants] = useState([]);

    // To preserve the listOfRestaurants
    const [filteredRestaurants, setFilteredRestaurants] = useState([]);

    const [searchText, setSearchText] = useState("");

    // Above Line is same as (Array Destructuring)--
    // const arr = useState(resList);
    // const [listOfRestaurants, setListOfRestaurants] = arr;
    // const listOfRestaurants = arr[0];
    // const setListOfRestaurants = arr[1];

    // *Another IMP Hook for React API--
    useEffect(() => {
        // This will be called when the page is rendered!
        // console.log("useEffect is called!");

        // Fetch data from outside world.
        fetchData();
    }, []);

    // console.log("Body Rendered!");

    const fetchData = async () => {
        const data = await fetch(
            // Swiggy API--
            // It cannot be fetch normally due to CORS, prevented using allow CORS extension--
            "https://www.swiggy.com/dapi/restaurants/list/v5?lat=22.6734596&lng=75.8789932&is-seo-homepage-enabled=true&page_type=DESKTOP_WEB_LISTING"
        );

        // CONVERT INTO JSON FILE--
        const json = await data.json();
        console.log(json);

        // Normal Obtaining Path for the restaurant list--
        // setListOfRestaurants(
        //     json.data.cards[2].card.card.gridElements.infoWithStyle.restaurants
        // );

        // Optional Chaining--
        setListOfRestaurants(
            json?.data?.cards[2]?.card?.card?.gridElements?.infoWithStyle
                ?.restaurants
        );
        setFilteredRestaurants(
            json?.data?.cards[2]?.card?.card?.gridElements?.infoWithStyle
                ?.restaurants
        );
    };

    // Conditional Rendering(On basis of some condition) --
    // if (listOfRestaurants.length === 0) {
    //     // Loading.. is not a good practice, rather use Shimmer--
    //     // return <h1>Loading...</h1>;

    //     return <Shimmer />;
    // }

    // Ternary Operator--
    return listOfRestaurants.length === 0 ? (
        <Shimmer />
    ) : (
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
                                return res.info.name
                                    .toLowerCase()
                                    .includes(searchText.toLowerCase());
                            }
                        );

                        // console.log(searchedRestaurant.length);

                        // Update List--
                        setFilteredRestaurants(searchedRestaurant);
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
                        setFilteredRestaurants(filteredList);
                        console.log("button Clicked!");
                    }}
                >
                    Top Rated Restaurant
                </button>
            </div>

            <div className="restaurant-container">
                {/* Iterate Over Each Element with Map function of JS */}
                {filteredRestaurants.map((restaurant) => (
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
