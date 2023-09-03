import RestaurantCard from "./RestuarantCard";
// import resList from "../utils/mockData";
import { useState, useEffect } from "react";
import Shimmer from "./Shimmer";
import { SWIGGY_URL } from "../utils/constants";
import { Link } from "react-router-dom";
import useOnlineStatus from "../utils/useOnlineStatus";

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

    // Array of Size 2, [current state value, function to change state value]
    console.log(useState());
    // console.log(useEffect());

    // console.log("Body Rendered!");

    const fetchData = async () => {
        const data = await fetch(
            // Swiggy API--
            // It cannot be fetch normally due to CORS, prevented using allow CORS extension--
            SWIGGY_URL
        );

        // CONVERT INTO JSON FILE--
        const json = await data.json();
        // console.log(json);

        // Normal Obtaining Path for the restaurant list--
        // setListOfRestaurants(
        //     json.data.cards[2].card.card.gridElements.infoWithStyle.restaurants
        // );
        // setFilteredRestaurants(
        //     json.data.cards[2].card.card.gridElements.infoWithStyle.restaurants
        // );

        // Optional Chaining--
        // setListOfRestaurants(
        //     json?.data?.cards[2]?.card?.card?.gridElements?.infoWithStyle
        //         ?.restaurants
        // );
        // setFilteredRestaurants(
        //     json?.data?.cards[2]?.card?.card?.gridElements?.infoWithStyle
        //         ?.restaurants
        // );

        // initialize checkJsonData() function to check Swiggy Restaurant data
        async function checkJsonData(jsonData) {
            for (let i = 0; i < jsonData?.data?.cards.length; i++) {
                // updated state variable restaurants with Swiggy API data
                // initialize checkData for Swiggy Restaurant data
                let checkData =
                    jsonData?.data?.cards[i]?.card?.card?.gridElements
                        ?.infoWithStyle?.restaurants;

                // if checkData is not undefined then return it
                if (checkData !== undefined) {
                    return checkData;
                }
            }
        }
        const resData = await checkJsonData(json);

        setListOfRestaurants(resData);
        setFilteredRestaurants(resData);
    };

    // Conditional Rendering(On basis of some condition) --
    // if (listOfRestaurants.length === 0) {
    //     // Loading.. is not a good practice, rather use Shimmer--
    //     // return <h1>Loading...</h1>;

    //     return <Shimmer />;
    // }

    // Show Online Status--
    const onlineStatus = useOnlineStatus();

    if (onlineStatus === false) {
        return (
            <h1>Looks like you are OFFLINE, Check your internet connection</h1>
        );
    }

    // Ternary Operator--
    return listOfRestaurants.length === 0 ? (
        <Shimmer />
    ) : (
        <div className="body">
            <div className="filter flex">
                <div className="search mr-4 px-4">
                    <input
                        type="text"
                        className="border border-solid border-black"
                        placeholder="Search Restaurant"
                        value={searchText}
                        onChange={(txt) => {
                            console.log(txt.target.value);
                            setSearchText(txt.target.value);
                        }}
                    ></input>
                    <button
                        className="search-btn px-4 py-2 m-4 bg-green-100 rounded-lg"
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
                <div className="flex items-center">
                    <button
                        className="filter-btn px-4 py-2 bg-gray-100 rounded-lg"
                        onClick={() => {
                            // Filter Logic Here!
                            const filteredList = listOfRestaurants.filter(
                                (res) => {
                                    return res.info.avgRating > 4;
                                }
                            );
                            // Update List--
                            setFilteredRestaurants(filteredList);
                            console.log("button Clicked!");
                        }}
                    >
                        Top Rated Restaurant
                    </button>
                </div>
            </div>

            <div className="restaurant-container flex flex-wrap">
                {/* Iterate Over Each Element with Map function of JS */}
                {filteredRestaurants.map((restaurant) => (
                    // Key is important to prevent re-rendering of all the entries previously rendered.
                    // Key needs to be unique Id or indexes in worst case.
                    <Link
                        key={restaurant.info.id}
                        to={"/restaurants/" + restaurant.info.id}
                    >
                        <RestaurantCard resData={restaurant} />
                    </Link>
                ))}
            </div>
        </div>
    );
};

export default Body;
