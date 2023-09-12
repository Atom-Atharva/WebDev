import { CDN_URL } from "../utils/constants";

// For Inline CSS (attribute : style = {styleCard})--
const styleCard = {
    backgroundColor: "#F0F0F0",
};

// Restaurant Card--
// We can pass props as (props) => ({resName, cuisine, ...})
const RestaurantCard = (props) => {
    // const { resName, cuisine } = props;
    // console.log(resName);
    // console.log(cuisine);
    const { resData } = props;

    // *Equivalent to resData.info.name, resData.info.cuisines, etc...
    const { cloudinaryImageId, name, cuisines, avgRating, costForTwo } =
        resData?.info;
    return (
        // Inline CSS -- style={{backgroundColor:#F0F0F0}}
        <div
            className="restaurant-card m-4 p-4 w-[250px] rounded-lg bg-gray-100 hover:bg-gray-200"
            // style={styleCard}
        >
            <img
                className="rounded-lg"
                alt="logo"
                src={CDN_URL + cloudinaryImageId}
            ></img>
            <h3 className="font-bold py-4 text-lg">{name}</h3>
            <h4>{cuisines.join(", ")}</h4>
            <h4>{avgRating + " stars"}</h4>
            <h4>{costForTwo}</h4>
        </div>
    );
};

// Higher Order Function--
// Takes RestaurantCard as INPUT--
export const withPromotedLabel = (RestaurantCard) => {
    // Returns a component with some changes--
    return (props) => {
        // Returns a JSX of the component--
        return (
            <div>
                <label className="absolute bg-black text-white m-2 p-2 rounded-lg">
                    Promoted
                </label>
                <RestaurantCard {...props} />
            </div>
        );
    };
};

export default RestaurantCard;
