// import { useState } from "react";
import ItemList from "./ItemList";

const RestaurantCategory = ({ data, showItem,setShowIndex }) => {
    // console.log(data);

    // State Variables--
    // Uncontrolled Variable: Depends on the corresponding Category.
    // const [showItem, setShowItem] = useState(false);

    // Handling Click ON Header--
    const handleClick = () => {
        // console.log("clicked!");
        // setShowItem(!showItem);

        setShowIndex();
    };

    return (
        <div>
            {/* Header */}
            <div className="w-6/12 bg-gray-50 shadow-md my-4 mx-auto p-4">
                <div
                    className={`flex justify-between cursor-pointer`}
                    onClick={handleClick}
                >
                    <span className="font-bold text-lg">
                        {data.title} ({data.itemCards.length})
                    </span>
                    <span>⬇️</span>
                </div>

                {/* Accordion Body */}
                {showItem && <ItemList items={data.itemCards} />}
            </div>
        </div>
    );
};

export default RestaurantCategory;
