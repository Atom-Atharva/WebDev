// import { useState, useEffect } from "react";
// import { MENU_URL } from "../utils/constants";
import Shimmer from "./Shimmer";
import { useParams } from "react-router-dom";
import useRestaurantMenu from "../utils/useRestaurantMenu";
import RestaurantCategory from "./RestaurantCategory";
import { useState } from "react";

const RestaurantMenu = () => {
    // const [resInfo, setResInfo] = useState(null);

    // Evaluate Parameter of Dynamic Route--
    // const params = useParams();
    // console.log(params); // Object ---> {resId: 2324}

    const { resId } = useParams();
    // console.log(resId);

    // useEffect(() => {
    //     fetchMenu();
    // }, []);

    // const fetchMenu = async () => {
    //     const data = await fetch(MENU_URL + resId);
    //     const json = await data.json();
    //     // console.log(json);

    //     setResInfo(json.data);
    // };

    // Controls Child Environment--
    const [showIndex, setShowIndex] = useState(0);

    // Custom Hook--
    const resInfo = useRestaurantMenu(resId);

    if (resInfo === null) {
        return <Shimmer />;
    }

    // While the data is been fetched the variables are set to be undefined.
    // To Solve the error either return when null before accessing null.
    const { name, cuisines, costForTwoMessage } =
        resInfo?.cards[0]?.card?.card?.info || {};

    // Menu Items inside ItemCards--
    const { itemCards } =
        resInfo?.cards[2]?.groupedCard?.cardGroupMap?.REGULAR?.cards[1]?.card
            ?.card;

    // All Cards Available--
    // console.log(resInfo?.cards[2]?.groupedCard?.cardGroupMap?.REGULAR?.cards);

    // Find Out All Categories--
    const categories =
        resInfo?.cards[2]?.groupedCard?.cardGroupMap?.REGULAR?.cards.filter(
            (cat) =>
                cat.card?.card?.["@type"] ===
                "type.googleapis.com/swiggy.presentation.food.v2.ItemCategory"
        );

    // Filtered Data for ITEM CATEGORY ONLY--
    // console.log(categories);

    return (
        <div className="menu text-center">
            <h1 className="font-bold my-6 text-2xl">{name}</h1>
            <p className="font-bold text-lg">
                {cuisines.join(", ")} - {costForTwoMessage}
            </p>

            {/** Categories Accordions */}
            {categories.map((category, index) => {
                // Controlled Component--
                return (
                    <RestaurantCategory
                        key={category.card.card.title}
                        data={category?.card?.card}
                        showItem={index === showIndex ? true : false}
                        setShowIndex={() =>
                            index == showIndex
                                ? setShowIndex(null)
                                : setShowIndex(index)
                        }
                    />
                );
            })}
        </div>
    );
};

export default RestaurantMenu;
