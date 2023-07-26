import React from "react";
import ReactDOM from "react-dom/client";

/**
 *
 * Header
 *  - Logo
 *  - Nav Items
 * Body
 *  - Search
 *  - Restaurant Container
 *      - Restaurant Card
 *          - img
 *          - name of Rest, star Rating, Cuisine, delivery time.
 * Footer
 *  - Copyright
 *  - Links
 *  - Address
 *  - Contact
 *
 */

// Header Component--
const Header = () => {
    return (
        <div className="header">
            <div className="logo-container">
                <img src="https://png.pngtree.com/template/20191120/ourmid/pngtree-red-chilli-food-logo-design-your-company-image_334205.jpg"></img>
            </div>
            <div className="nav-items">
                <ul>
                    <li>Home</li>
                    <li>About Us</li>
                    <li>Contact Us</li>
                    <li>Cart</li>
                </ul>
            </div>
        </div>
    );
};

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
            <img
                alt="logo"
                src={
                    "https://res.cloudinary.com/swiggy/image/upload/fl_lossy,f_auto,q_auto,w_660/" +
                    cloudinaryImageId
                }
            ></img>
            <h3>{name}</h3>
            <h4>{cuisines.join(", ")}</h4>
            <h4>{avgRating + " stars"}</h4>
            <h4>{costForTwo}</h4>
        </div>
    );
};

// JSON Data for Apna Sweets--
const resObj = {
    info: {
        id: "199666",
        name: "Apna Sweets",
        cloudinaryImageId: "f3drzbvl7ohsoryzwcwc",
        locality: "Sudama Nagar",
        areaName: "Parshwanath Nagar",
        costForTwo: "₹500 for two",
        cuisines: [
            "North Indian",
            "Sweets",
            "Beverages",
            "Street Food",
            "South Indian",
            "Fast Food",
            "Chinese",
            "Desserts",
        ],
        avgRating: 4.1,
        veg: true,
        feeDetails: {
            restaurantId: "199666",
            fees: [
                {
                    name: "BASE_DISTANCE",
                    fee: 3300,
                },
                {
                    name: "BASE_TIME",
                },
                {
                    name: "ANCILLARY_SURGE_FEE",
                },
            ],
            totalFee: 3300,
        },
        parentId: "8960",
        avgRatingString: "4.1",
        totalRatingsString: "10K+",
        promoted: true,
        adTrackingId:
            "cid=7551984~p=1~eid=00000189-8d6b-b13a-0427-3b060043010a~srvts=1690294792506~87168",
        sla: {
            deliveryTime: 29,
            lastMileTravel: 4.6,
            serviceability: "SERVICEABLE",
            slaString: "29 mins",
            lastMileTravelString: "4.6 km",
            iconType: "ICON_TYPE_EMPTY",
        },
        availability: {
            nextCloseTime: "2023-07-25 22:30:00",
            opened: true,
        },
        badges: {},
        isOpen: true,
        type: "F",
        badgesV2: {
            entityBadges: {
                imageBased: {},
                textBased: {},
                textExtendedBadges: {},
            },
        },
        aggregatedDiscountInfoV3: {
            header: "40% OFF",
            subHeader: "UPTO ₹80",
        },
        orderabilityCommunication: {
            title: {},
            subTitle: {},
            message: {},
            customIcon: {},
        },
        differentiatedUi: {
            displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
            differentiatedUiMediaDetails: {
                maxDuration: "3000",
                mediaType: "ADS_MEDIA_ENUM_IMAGE",
                lottie: {},
                video: {},
            },
        },
        reviewsSummary: {},
        displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
    },
    analytics: {
        context: "seo-data-7afa227a-ea09-42f9-ab58-47884094b365",
    },
    cta: {
        link: "https://www.swiggy.com/restaurants/apna-sweets-sudama-nagar-parshwanath-nagar-indore-199666",
        text: "RESTAURANT_MENU",
        type: "WEBLINK",
    },
    widgetId: "collectionV5RestaurantListWidget_SimRestoRelevance_BCP_byName",
};

const resObj2 = {
    info: {
        id: "84070",
        name: "Gurukripa Restaurant Sarwate",
        cloudinaryImageId: "g5txnz35wlrgbskk3r8y",
        locality: "Sarwate",
        areaName: "South Tukoganj",
        costForTwo: "₹250 for two",
        cuisines: [
            "North Indian",
            "Thalis",
            "Indian",
            "Fast Food",
            "Chinese",
            "Beverages",
            "Desserts",
            "Jain",
            "Punjabi",
        ],
        avgRating: 4,
        veg: true,
        feeDetails: {
            restaurantId: "84070",
            fees: [
                {
                    name: "BASE_DISTANCE",
                    fee: 3300,
                },
                {
                    name: "BASE_TIME",
                },
                {
                    name: "ANCILLARY_SURGE_FEE",
                },
            ],
            totalFee: 3300,
        },
        parentId: "92204",
        avgRatingString: "4.0",
        totalRatingsString: "10K+",
        promoted: true,
        adTrackingId:
            "cid=7551948~p=2~eid=00000189-8d6b-b13a-0427-3b070043026a~srvts=1690294792506~87168",
        sla: {
            deliveryTime: 31,
            lastMileTravel: 4.6,
            serviceability: "SERVICEABLE",
            slaString: "31 mins",
            lastMileTravelString: "4.6 km",
            iconType: "ICON_TYPE_EMPTY",
        },
        availability: {
            nextCloseTime: "2023-07-25 23:59:00",
            opened: true,
        },
        badges: {},
        isOpen: true,
        type: "F",
        badgesV2: {
            entityBadges: {
                imageBased: {},
                textBased: {},
                textExtendedBadges: {},
            },
        },
        aggregatedDiscountInfoV3: {
            header: "₹125 OFF",
            subHeader: "ABOVE ₹199",
            discountTag: "FLAT DEAL",
        },
        orderabilityCommunication: {
            title: {},
            subTitle: {},
            message: {},
            customIcon: {},
        },
        differentiatedUi: {
            displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
            differentiatedUiMediaDetails: {
                maxDuration: "3000",
                mediaType: "ADS_MEDIA_ENUM_IMAGE",
                lottie: {},
                video: {},
            },
        },
        reviewsSummary: {},
        displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
    },
    analytics: {
        context: "seo-data-7afa227a-ea09-42f9-ab58-47884094b365",
    },
    cta: {
        link: "https://www.swiggy.com/restaurants/gurukripa-restaurant-sarwate-sarwate-south-tukoganj-indore-84070",
        text: "RESTAURANT_MENU",
        type: "WEBLINK",
    },
    widgetId: "collectionV5RestaurantListWidget_SimRestoRelevance_BCP_byName",
};

const resObj3 = {
    info: {
        id: "292119",
        name: "Nafees restaurant",
        cloudinaryImageId: "bmmsvclvyb6fuqb9hxyo",
        locality: "Professor Colony",
        areaName: "Bhawar Kuan",
        costForTwo: "₹400 for two",
        cuisines: [
            "Mughlai",
            "Biryani",
            "North Indian",
            "Chinese",
            "Snacks",
            "Desserts",
        ],
        avgRating: 4,
        feeDetails: {
            restaurantId: "292119",
            fees: [
                {
                    name: "BASE_DISTANCE",
                    fee: 2200,
                },
                {
                    name: "BASE_TIME",
                },
                {
                    name: "ANCILLARY_SURGE_FEE",
                },
            ],
            totalFee: 2200,
        },
        parentId: "10713",
        avgRatingString: "4.0",
        totalRatingsString: "10K+",
        sla: {
            deliveryTime: 22,
            lastMileTravel: 2.6,
            serviceability: "SERVICEABLE",
            slaString: "22 mins",
            lastMileTravelString: "2.6 km",
            iconType: "ICON_TYPE_EMPTY",
        },
        availability: {
            nextCloseTime: "2023-07-25 23:30:00",
            opened: true,
        },
        badges: {},
        isOpen: true,
        type: "F",
        badgesV2: {
            entityBadges: {
                imageBased: {},
                textBased: {},
                textExtendedBadges: {},
            },
        },
        aggregatedDiscountInfoV3: {
            header: "₹125 OFF",
            subHeader: "ABOVE ₹199",
            discountTag: "FLAT DEAL",
        },
        orderabilityCommunication: {
            title: {},
            subTitle: {},
            message: {},
            customIcon: {},
        },
        differentiatedUi: {
            displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
            differentiatedUiMediaDetails: {
                maxDuration: "3000",
                mediaType: "ADS_MEDIA_ENUM_IMAGE",
                lottie: {},
                video: {},
            },
        },
        reviewsSummary: {},
        displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
    },
    analytics: {
        context: "seo-data-7afa227a-ea09-42f9-ab58-47884094b365",
    },
    cta: {
        link: "https://www.swiggy.com/restaurants/nafees-restaurant-professor-colony-bhawar-kuan-indore-292119",
        text: "RESTAURANT_MENU",
        type: "WEBLINK",
    },
    widgetId: "collectionV5RestaurantListWidget_SimRestoRelevance_BCP_byName",
};

const resObj4 = {
    info: {
        id: "717182",
        name: "Indian Coffee House",
        cloudinaryImageId: "aba45375462798eb6c7727b639f893db",
        locality: "khandwa Road",
        areaName: "Bhawar Kuan",
        costForTwo: "₹300 for two",
        cuisines: ["Indian", "South Indian", "Biryani", "Chinese", "Beverages"],
        avgRating: 4.5,
        feeDetails: {
            restaurantId: "717182",
            fees: [
                {
                    name: "BASE_DISTANCE",
                    fee: 2200,
                },
                {
                    name: "BASE_TIME",
                },
                {
                    name: "ANCILLARY_SURGE_FEE",
                },
            ],
            totalFee: 2200,
        },
        parentId: "106448",
        avgRatingString: "4.5",
        totalRatingsString: "10+",
        sla: {
            deliveryTime: 27,
            lastMileTravel: 1.6,
            serviceability: "SERVICEABLE",
            slaString: "27 mins",
            lastMileTravelString: "1.6 km",
            iconType: "ICON_TYPE_EMPTY",
        },
        availability: {
            nextCloseTime: "2023-07-25 22:30:00",
            opened: true,
        },
        badges: {},
        isOpen: true,
        aggregatedDiscountInfoV2: {},
        type: "F",
        badgesV2: {
            entityBadges: {
                imageBased: {},
                textBased: {},
                textExtendedBadges: {},
            },
        },
        orderabilityCommunication: {
            title: {},
            subTitle: {},
            message: {},
            customIcon: {},
        },
        differentiatedUi: {
            displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
            differentiatedUiMediaDetails: {
                maxDuration: "3000",
                mediaType: "ADS_MEDIA_ENUM_IMAGE",
                lottie: {},
                video: {},
            },
        },
        reviewsSummary: {},
        displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        isNewlyOnboarded: true,
    },
    analytics: {
        context: "seo-data-7afa227a-ea09-42f9-ab58-47884094b365",
    },
    cta: {
        link: "https://www.swiggy.com/restaurants/indian-coffee-house-khandwa-road-bhawar-kuan-indore-717182",
        text: "RESTAURANT_MENU",
        type: "WEBLINK",
    },
    widgetId: "collectionV5RestaurantListWidget_SimRestoRelevance_BCP_byName",
};

const resObj5 = {
    info: {
        id: "455875",
        name: "Guru kripa Rau Since -1987",
        cloudinaryImageId: "armyyafnwdvglosinqaz",
        locality: "Ab Road",
        areaName: "Rau ",
        costForTwo: "₹200 for two",
        cuisines: [
            "North Indian",
            "Thalis",
            "Chinese",
            "South Indian",
            "Fast Food",
            "Pizzas",
            "Italian",
            "Beverages",
            "Indian",
            "Jain",
        ],
        avgRating: 4.2,
        veg: true,
        feeDetails: {
            restaurantId: "455875",
            fees: [
                {
                    name: "BASE_DISTANCE",
                    fee: 9100,
                },
                {
                    name: "BASE_TIME",
                },
                {
                    name: "ANCILLARY_SURGE_FEE",
                },
            ],
            totalFee: 9100,
        },
        parentId: "336353",
        avgRatingString: "4.2",
        totalRatingsString: "5K+",
        promoted: true,
        adTrackingId:
            "cid=7551971~p=3~eid=00000189-8d6b-b13a-0427-3b0800430323~srvts=1690294792506~87168",
        sla: {
            deliveryTime: 38,
            lastMileTravel: 9.7,
            serviceability: "SERVICEABLE",
            slaString: "38 mins",
            lastMileTravelString: "9.7 km",
            iconType: "ICON_TYPE_EMPTY",
        },
        availability: {
            nextCloseTime: "2023-07-25 23:59:00",
            opened: true,
        },
        badges: {},
        isOpen: true,
        type: "F",
        badgesV2: {
            entityBadges: {
                imageBased: {},
                textBased: {},
                textExtendedBadges: {},
            },
        },
        aggregatedDiscountInfoV3: {
            header: "₹125 OFF",
            subHeader: "ABOVE ₹199",
            discountTag: "FLAT DEAL",
        },
        orderabilityCommunication: {
            title: {},
            subTitle: {},
            message: {},
            customIcon: {},
        },
        differentiatedUi: {
            displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
            differentiatedUiMediaDetails: {
                maxDuration: "3000",
                mediaType: "ADS_MEDIA_ENUM_IMAGE",
                lottie: {},
                video: {},
            },
        },
        reviewsSummary: {},
        displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
    },
    analytics: {
        context: "seo-data-7afa227a-ea09-42f9-ab58-47884094b365",
    },
    cta: {
        link: "https://www.swiggy.com/restaurants/guru-kripa-rau-since-1987-ab-road-rau-indore-455875",
        text: "RESTAURANT_MENU",
        type: "WEBLINK",
    },
    widgetId: "collectionV5RestaurantListWidget_SimRestoRelevance_BCP_byName",
};

// JSON Data for Restaurants--
const resList = [
    {
        info: {
            id: "64814",
            name: "The Belgian Waffle Co.",
            cloudinaryImageId: "yvsx0eg2orug7sfpdazr",
            locality: "Anand Bazar",
            areaName: "Old Palasia",
            costForTwo: "₹200 for two",
            cuisines: ["Waffle", "Desserts", "Ice Cream", "Beverages"],
            avgRating: 4.3,
            veg: true,
            feeDetails: {
                restaurantId: "64814",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 9700,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 9700,
            },
            parentId: "2233",
            avgRatingString: "4.3",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 34,
                lastMileTravel: 8.4,
                serviceability: "SERVICEABLE",
                slaString: "34 mins",
                lastMileTravelString: "8.4 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "20% OFF",
                subHeader: "UPTO ₹50",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/the-belgian-waffle-co-anand-bazar-old-palasia-indore-64814",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "79829",
            name: "Natural Ice Cream",
            cloudinaryImageId: "mjvpnvts8c2v4hatzzus",
            locality: "Opp Central Mall",
            areaName: "Rnt Marg",
            costForTwo: "₹150 for two",
            cuisines: ["Ice Cream", "Desserts"],
            avgRating: 4.6,
            veg: true,
            feeDetails: {
                restaurantId: "79829",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "2093",
            avgRatingString: "4.6",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 24,
                lastMileTravel: 6.5,
                serviceability: "SERVICEABLE",
                slaString: "24 mins",
                lastMileTravelString: "6.5 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "20% OFF",
                subHeader: "UPTO ₹50",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/natural-ice-cream-opp-central-mall-rnt-marg-indore-79829",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "84070",
            name: "Gurukripa Restaurant Sarwate",
            cloudinaryImageId: "g5txnz35wlrgbskk3r8y",
            locality: "Sarwate",
            areaName: "South Tukoganj",
            costForTwo: "₹250 for two",
            cuisines: [
                "North Indian",
                "Thalis",
                "Indian",
                "Fast Food",
                "Chinese",
                "Beverages",
                "Desserts",
                "Jain",
                "Punjabi",
            ],
            avgRating: 4,
            veg: true,
            feeDetails: {
                restaurantId: "84070",
                fees: [
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "BASE_DISTANCE",
                        fee: 9700,
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 9700,
            },
            parentId: "92204",
            avgRatingString: "4.0",
            totalRatingsString: "10K+",
            sla: {
                deliveryTime: 32,
                lastMileTravel: 8.1,
                serviceability: "SERVICEABLE",
                slaString: "32 mins",
                lastMileTravelString: "8.1 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-25 23:59:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "₹125 OFF",
                subHeader: "ABOVE ₹199",
                discountTag: "FLAT DEAL",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/gurukripa-restaurant-sarwate-sarwate-south-tukoganj-indore-84070",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "156145",
            name: "The Good Bowl",
            cloudinaryImageId: "owdqcxtoyeg5vcltrssr",
            locality: "Annapoorna FC",
            areaName: "Sudama Nagar",
            costForTwo: "₹400 for two",
            cuisines: [
                "Biryani",
                "North Indian",
                "Pastas",
                "Punjabi",
                "Desserts",
                "Beverages",
            ],
            avgRating: 4.1,
            feeDetails: {
                restaurantId: "156145",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "7918",
            avgRatingString: "4.1",
            totalRatingsString: "500+",
            sla: {
                deliveryTime: 29,
                lastMileTravel: 6.9,
                serviceability: "SERVICEABLE",
                slaString: "29 mins",
                lastMileTravelString: "6.9 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            aggregatedDiscountInfoV2: {},
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/the-good-bowl-annapoorna-fc-sudama-nagar-indore-156145",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "322539",
            name: "Barbeque Nation",
            cloudinaryImageId: "yllayyaltqyeear9nh2e",
            locality: "Treasure Island Mall",
            areaName: "Tukoganj",
            costForTwo: "₹600 for two",
            cuisines: [
                "North Indian",
                "Barbecue",
                "Biryani",
                "Kebabs",
                "Mughlai",
                "Desserts",
            ],
            avgRating: 3.5,
            feeDetails: {
                restaurantId: "322539",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "2438",
            avgRatingString: "3.5",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 34,
                lastMileTravel: 6.6,
                serviceability: "SERVICEABLE",
                slaString: "34 mins",
                lastMileTravelString: "6.6 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-25 23:30:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "50% OFF",
                subHeader: "UPTO ₹100",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/barbeque-nation-treasure-island-mall-tukoganj-indore-322539",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "322540",
            name: "UBQ BY Barbeque Nation",
            cloudinaryImageId: "ousldxwz6z3cypd2pygf",
            locality: "Treasure Island Mall",
            areaName: "Tukoganj",
            costForTwo: "₹300 for two",
            cuisines: [
                "North Indian",
                "Barbecue",
                "Biryani",
                "Kebabs",
                "Mughlai",
                "Desserts",
            ],
            avgRating: 3.8,
            feeDetails: {
                restaurantId: "322540",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "10804",
            avgRatingString: "3.8",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 33,
                lastMileTravel: 6.6,
                serviceability: "SERVICEABLE",
                slaString: "33 mins",
                lastMileTravelString: "6.6 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-25 23:30:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "30% OFF",
                subHeader: "UPTO ₹75",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/ubq-by-barbeque-nation-treasure-island-mall-tukoganj-indore-322540",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "80653",
            name: "Sweet Truth - Cake and Desserts",
            cloudinaryImageId: "3ec8bccd0fc2c6303d7602dd642248d5",
            locality: "Raghav Regency",
            areaName: "Sudama Nagar",
            costForTwo: "₹450 for two",
            cuisines: ["Snacks", "Bakery", "Desserts", "Beverages"],
            avgRating: 4.2,
            feeDetails: {
                restaurantId: "80653",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "4444",
            avgRatingString: "4.2",
            totalRatingsString: "500+",
            sla: {
                deliveryTime: 27,
                lastMileTravel: 6.9,
                serviceability: "SERVICEABLE",
                slaString: "27 mins",
                lastMileTravelString: "6.9 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            aggregatedDiscountInfoV2: {},
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/sweet-truth-cake-and-desserts-raghav-regency-sudama-nagar-indore-80653",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "80650",
            name: "Faasos - Wraps & Rolls",
            cloudinaryImageId: "af33b81798b11deba338e94b7585d348",
            locality: "Raghav Regency",
            areaName: "Sudama Nagar",
            costForTwo: "₹200 for two",
            cuisines: [
                "Kebabs",
                "Fast Food",
                "Snacks",
                "North Indian",
                "American",
                "Healthy Food",
                "Desserts",
                "Beverages",
            ],
            avgRating: 3.9,
            feeDetails: {
                restaurantId: "80650",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "21809",
            avgRatingString: "3.9",
            totalRatingsString: "5K+",
            sla: {
                deliveryTime: 29,
                lastMileTravel: 6.9,
                serviceability: "SERVICEABLE",
                slaString: "29 mins",
                lastMileTravelString: "6.9 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            aggregatedDiscountInfoV2: {},
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/faasos-wraps-and-rolls-raghav-regency-sudama-nagar-indore-80650",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "80649",
            name: "Behrouz Biryani",
            cloudinaryImageId: "49c27c020e946f8f4fc13fdc9038525c",
            locality: "Raghav Regency",
            areaName: "Sudama Nagar",
            costForTwo: "₹500 for two",
            cuisines: [
                "Biryani",
                "Mughlai",
                "Lucknowi",
                "Hyderabadi",
                "Kebabs",
                "North Indian",
                "Desserts",
                "Beverages",
            ],
            avgRating: 4.2,
            feeDetails: {
                restaurantId: "80649",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "1803",
            avgRatingString: "4.2",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 30,
                lastMileTravel: 6.9,
                serviceability: "SERVICEABLE",
                slaString: "30 mins",
                lastMileTravelString: "6.9 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            aggregatedDiscountInfoV2: {},
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/behrouz-biryani-raghav-regency-sudama-nagar-indore-80649",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "86044",
            name: "LunchBox - Meals and Thalis",
            cloudinaryImageId: "qa9nfrq8aomor6glzcpo",
            locality: "Raghav Regency",
            areaName: "Sudama Nagar",
            costForTwo: "₹200 for two",
            cuisines: [
                "Biryani",
                "North Indian",
                "Punjabi",
                "Healthy Food",
                "Desserts",
                "Beverages",
            ],
            avgRating: 4.2,
            feeDetails: {
                restaurantId: "86044",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "4925",
            avgRatingString: "4.2",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 30,
                lastMileTravel: 6.9,
                serviceability: "SERVICEABLE",
                slaString: "30 mins",
                lastMileTravelString: "6.9 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "60% OFF",
                subHeader: "UPTO ₹120",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/lunchbox-meals-and-thalis-raghav-regency-sudama-nagar-indore-86044",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "67970",
            name: "Subway",
            cloudinaryImageId: "1ace5fa65eff3e1223feb696c956b38b",
            locality: "Snehnagar",
            areaName: "Sapna Sangeeta",
            costForTwo: "₹350 for two",
            cuisines: [
                "Healthy Food",
                "Salads",
                "Snacks",
                "Desserts",
                "Beverages",
            ],
            avgRating: 3.9,
            feeDetails: {
                restaurantId: "67970",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 3700,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 3700,
            },
            parentId: "2",
            avgRatingString: "3.9",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 20,
                lastMileTravel: 3.6,
                serviceability: "SERVICEABLE",
                slaString: "20 mins",
                lastMileTravelString: "3.6 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 00:30:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            aggregatedDiscountInfoV2: {},
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/subway-snehnagar-sapna-sangeeta-indore-67970",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "65543",
            name: "Pizza Hut",
            cloudinaryImageId: "2b4f62d606d1b2bfba9ba9e5386fabb7",
            locality: "Saket Square",
            areaName: "Old Palasia",
            costForTwo: "₹350 for two",
            cuisines: ["Pizzas"],
            avgRating: 3.9,
            feeDetails: {
                restaurantId: "65543",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 9700,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 9700,
            },
            parentId: "721",
            avgRatingString: "3.9",
            totalRatingsString: "5K+",
            sla: {
                deliveryTime: 36,
                lastMileTravel: 8.1,
                serviceability: "SERVICEABLE",
                slaString: "36 mins",
                lastMileTravelString: "8.1 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "FREE ITEM",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/pizza-hut-saket-square-old-palasia-indore-65543",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "303103",
            name: "KFC",
            cloudinaryImageId: "56c9ab92bd79745fd152a30fa2525426",
            locality: "RNT Marg",
            areaName: "South Tukoganj",
            costForTwo: "₹400 for two",
            cuisines: ["Burgers", "Biryani", "American", "Snacks", "Fast Food"],
            avgRating: 3.8,
            feeDetails: {
                restaurantId: "303103",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "547",
            avgRatingString: "3.8",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 27,
                lastMileTravel: 6.3,
                serviceability: "SERVICEABLE",
                slaString: "27 mins",
                lastMileTravelString: "6.3 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 00:45:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "20% OFF",
                subHeader: "UPTO ₹50",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/kfc-rnt-marg-south-tukoganj-indore-303103",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "64532",
            name: "Sagar Gaire",
            cloudinaryImageId: "irki7zudjxrbbmtcvpgy",
            locality: "Chappan Dukan",
            areaName: "New Palasia",
            costForTwo: "₹300 for two",
            cuisines: ["Punjabi", "Chinese", "Italian", "Thalis"],
            avgRating: 4,
            veg: true,
            feeDetails: {
                restaurantId: "64532",
                fees: [
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "BASE_DISTANCE",
                        fee: 8200,
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 8200,
            },
            parentId: "7049",
            avgRatingString: "4.0",
            totalRatingsString: "10K+",
            sla: {
                deliveryTime: 32,
                lastMileTravel: 7.5,
                serviceability: "SERVICEABLE",
                slaString: "32 mins",
                lastMileTravelString: "7.5 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-25 23:59:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "₹100 OFF",
                subHeader: "ABOVE ₹249",
                discountTag: "FLAT DEAL",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/sagar-gaire-chappan-dukan-new-palasia-indore-64532",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "64541",
            name: "Oye24",
            cloudinaryImageId: "r3hc8fyoajjgkmjszx2k",
            locality: "91th Scheme",
            areaName: "Pardesipura",
            costForTwo: "₹300 for two",
            cuisines: [
                "North Indian",
                "Pizzas",
                "South Indian",
                "Desserts",
                "Chinese",
                "Thalis",
                "Indian",
            ],
            avgRating: 3.9,
            veg: true,
            feeDetails: {
                restaurantId: "64541",
                fees: [
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "BASE_DISTANCE",
                        fee: 9700,
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 9700,
            },
            parentId: "5208",
            avgRatingString: "3.9",
            totalRatingsString: "10K+",
            sla: {
                deliveryTime: 31,
                lastMileTravel: 8.7,
                serviceability: "SERVICEABLE",
                slaString: "31 mins",
                lastMileTravelString: "8.7 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-25 23:59:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "₹100 OFF",
                subHeader: "ABOVE ₹249",
                discountTag: "FLAT DEAL",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/oye24-91th-scheme-pardesipura-indore-64541",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "73369",
            name: "Maa Ki Rasoi",
            cloudinaryImageId: "b1h0agx8ysx7w6ybrygc",
            locality: "Gopur Square",
            areaName: "Sudama Nagar",
            costForTwo: "₹200 for two",
            cuisines: ["North Indian", "Thalis", "South Indian", "Chinese"],
            avgRating: 4,
            veg: true,
            feeDetails: {
                restaurantId: "73369",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 8200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 8200,
            },
            parentId: "401429",
            avgRatingString: "4.0",
            totalRatingsString: "10K+",
            sla: {
                deliveryTime: 28,
                lastMileTravel: 7,
                serviceability: "SERVICEABLE",
                slaString: "28 mins",
                lastMileTravelString: "7.0 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-25 23:59:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "50% OFF",
                discountTag: "FLAT DEAL",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/maa-ki-rasoi-gopur-square-sudama-nagar-indore-73369",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "80652",
            name: "Firangi Bake",
            cloudinaryImageId: "v9qsbs5qxvtq8jln33sw",
            locality: "Raghav Regency",
            areaName: "Sudama Nagar",
            costForTwo: "₹400 for two",
            cuisines: [
                "Pizzas",
                "Pastas",
                "Italian",
                "Mexican",
                "Healthy Food",
                "Desserts",
                "Beverages",
            ],
            avgRating: 4,
            feeDetails: {
                restaurantId: "80652",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 7200,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 7200,
            },
            parentId: "3952",
            avgRatingString: "4.0",
            totalRatingsString: "500+",
            sla: {
                deliveryTime: 35,
                lastMileTravel: 6.9,
                serviceability: "SERVICEABLE",
                slaString: "35 mins",
                lastMileTravelString: "6.9 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 01:00:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            aggregatedDiscountInfoV2: {},
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/firangi-bake-raghav-regency-sudama-nagar-indore-80652",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "224034",
            name: "Maa Ki Rasoi - Vijay Nagar",
            cloudinaryImageId: "22d76936a42e265be736b160b526b32e",
            locality: "Mangal city",
            areaName: "Vijay Nagar",
            costForTwo: "₹250 for two",
            cuisines: [
                "North Indian",
                "Thalis",
                "South Indian",
                "Chinese",
                "Fast Food",
                "Biryani",
            ],
            avgRating: 3.9,
            veg: true,
            feeDetails: {
                restaurantId: "224034",
                fees: [
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "BASE_DISTANCE",
                        fee: 12000,
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 12000,
            },
            parentId: "4107",
            avgRatingString: "3.9",
            totalRatingsString: "10K+",
            sla: {
                deliveryTime: 34,
                lastMileTravel: 10.4,
                serviceability: "SERVICEABLE",
                slaString: "34 mins",
                lastMileTravelString: "10.4 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-26 04:00:00",
                opened: true,
            },
            badges: {},
            select: true,
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "₹125 OFF",
                subHeader: "ABOVE ₹249",
                discountTag: "FLAT DEAL",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/maa-ki-rasoi-vijay-nagar-mangal-city-vijay-nagar-indore-224034",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "362475",
            name: "Social",
            cloudinaryImageId: "eerbyy1fi3pbotrwgzux",
            locality: "MR 10 Road",
            areaName: "Pushp Vihar Colony",
            costForTwo: "₹600 for two",
            cuisines: [
                "North Indian",
                "Chinese",
                "Fast Food",
                "Biryani",
                "Pizzas",
                "Salads",
                "Kebabs",
                "Juices",
                "Desserts",
                "Beverages",
            ],
            avgRating: 4.1,
            feeDetails: {
                restaurantId: "362475",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 12800,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 12800,
            },
            parentId: "2146",
            avgRatingString: "4.1",
            totalRatingsString: "1K+",
            sla: {
                deliveryTime: 38,
                lastMileTravel: 11.6,
                serviceability: "SERVICEABLE",
                slaString: "38 mins",
                lastMileTravelString: "11.6 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-25 23:30:00",
                opened: true,
            },
            badges: {
                imageBadges: [
                    {
                        imageId: "newg.png",
                        description: "Gourmet",
                    },
                ],
            },
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {
                        badgeObject: [
                            {
                                attributes: {
                                    description: "Gourmet",
                                    imageId: "newg.png",
                                },
                            },
                        ],
                    },
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "₹125 OFF",
                subHeader: "ABOVE ₹249",
                discountTag: "FLAT DEAL",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/social-mr-10-road-pushp-vihar-colony-indore-362475",
            type: "WEBLINK",
        },
    },
    {
        info: {
            id: "366008",
            name: "BOSS Burger",
            cloudinaryImageId: "d6uvdehvit3rjtcnrnzh",
            locality: "C-21 Business Park",
            areaName: "131 Scheme",
            costForTwo: "₹500 for two",
            cuisines: ["Burgers", "American", "Fast Food", "Snacks"],
            avgRating: 4.2,
            feeDetails: {
                restaurantId: "366008",
                fees: [
                    {
                        name: "BASE_DISTANCE",
                        fee: 12800,
                    },
                    {
                        name: "BASE_TIME",
                    },
                    {
                        name: "ANCILLARY_SURGE_FEE",
                    },
                ],
                totalFee: 12800,
            },
            parentId: "8594",
            avgRatingString: "4.2",
            totalRatingsString: "500+",
            sla: {
                deliveryTime: 39,
                lastMileTravel: 11.6,
                serviceability: "SERVICEABLE",
                slaString: "39 mins",
                lastMileTravelString: "11.6 km",
                iconType: "ICON_TYPE_EMPTY",
            },
            availability: {
                nextCloseTime: "2023-07-25 23:30:00",
                opened: true,
            },
            badges: {},
            isOpen: true,
            type: "F",
            badgesV2: {
                entityBadges: {
                    imageBased: {},
                    textBased: {},
                    textExtendedBadges: {},
                },
            },
            aggregatedDiscountInfoV3: {
                header: "₹125 OFF",
                subHeader: "ABOVE ₹249",
                discountTag: "FLAT DEAL",
            },
            orderabilityCommunication: {
                title: {},
                subTitle: {},
                message: {},
                customIcon: {},
            },
            differentiatedUi: {
                displayType: "ADS_UI_DISPLAY_TYPE_ENUM_DEFAULT",
                differentiatedUiMediaDetails: {
                    mediaType: "ADS_MEDIA_ENUM_IMAGE",
                    lottie: {},
                    video: {},
                },
            },
            reviewsSummary: {},
            displayType: "RESTAURANT_DISPLAY_TYPE_DEFAULT",
        },
        analytics: {},
        cta: {
            link: "https://www.swiggy.com/restaurants/boss-burger-c-21-business-park-131-scheme-indore-366008",
            type: "WEBLINK",
        },
    },
];

// Body Container--
const Body = () => {
    return (
        <div className="body">
            <div className="search">Search</div>
            <div className="restaurant-container">
                <RestaurantCard
                    // props:
                    resData={resObj}
                />

                {/* <RestaurantCard
                    // props:
                    image="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTOLdZllVksO-ew1oHcG9hc0Mc-9hnZqrh1qw&usqp=CAU"
                    resName="Bapu ki Kutia"
                    cuisine="North Indian, Asian"
                    stars="4 stars"
                    delTime="25 mins"
                /> */}

                <RestaurantCard
                    // props:
                    resData={resList[0]}
                />

                {/* Itterate Over Each Element with Map function of JS */}
                {resList.map((restaurant) => (
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

// Footer Container
const Footer = () => {
    return (
        <div className="footer">
            <div className="copyright">
                <h5>©️ Atharva Sugandhi</h5>
            </div>
            <div className="link">
                <ul>
                    <li>Mail</li>
                    <li>Address</li>
                </ul>
            </div>
        </div>
    );
};

// Main Component--
const AppLayout = () => {
    return (
        <div className="app">
            <Header />
            <Body />
        </div>
    );
};

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<AppLayout />);
