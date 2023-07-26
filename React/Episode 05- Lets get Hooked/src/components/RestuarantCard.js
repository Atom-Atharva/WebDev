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
        <div className="restaurant-card" style={styleCard}>
            <img alt="logo" src={CDN_URL + cloudinaryImageId}></img>
            <h3>{name}</h3>
            <h4>{cuisines.join(", ")}</h4>
            <h4>{avgRating + " stars"}</h4>
            <h4>{costForTwo}</h4>
        </div>
    );
};

export default RestaurantCard;
