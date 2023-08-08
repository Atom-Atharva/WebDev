import { useState, useEffect } from "react";
import { MENU_URL } from "../utils/constants";
import Shimmer from "./Shimmer";
import { useParams } from "react-router-dom";

const RestaurantMenu = () => {
    const [resInfo, setResInfo] = useState(null);

    // Evaluate Parameter of Dynamic Route--
    const params = useParams();
    console.log(params); // Object ---> {resId: 2324}

    const { resId } = useParams();
    console.log(resId);

    useEffect(() => {
        fetchMenu();
    }, []);

    const fetchMenu = async () => {
        const data = await fetch(MENU_URL + resId);
        const json = await data.json();
        // console.log(json);

        setResInfo(json.data);
    };

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

    console.log(itemCards);

    return (
        <div className="menu">
            <h1>{name}</h1>
            <p>
                {cuisines.join(", ")} - {costForTwoMessage}
            </p>

            <h2>Menu</h2>
            <ul>
                {itemCards.map((item) => {
                    return (
                        <li key={item.card.info.id}>
                            {item.card.info.name} - Rs.
                            {item.card.info.price / 100}
                        </li>
                    );
                })}

                {/* <li>{itemCards[0].card.info.name}</li>
                <li>{itemCards[1].card.info.name}</li>
                <li>Item2</li>
                <li>Item3</li>
                <li>Item4</li> */}
            </ul>
        </div>
    );
};

export default RestaurantMenu;
