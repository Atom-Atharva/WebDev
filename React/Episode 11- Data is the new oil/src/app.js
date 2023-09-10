import React, { lazy, Suspense, useEffect, useState } from "react";
import ReactDOM from "react-dom/client";
import Header from "./components/Header";
import Body from "./components/Body";
// import About from "./components/About";
import Contact from "./components/Contact";
import { createBrowserRouter, RouterProvider, Outlet } from "react-router-dom";
import Error from "./components/Error";
import RestaurantMenu from "./components/RestaurantMenu";
import Shimmer from "./components/Shimmer";
import UserContext from "./utils/UserContext";

// Normal Loading--
// import Grocery from "./components/Grocery";

// Lazy Loading--
// Chunking--
// On Demand Loading--
// Has its own bundler
const Grocery = lazy(() => import("./components/Grocery"));
const About = lazy(() => import("./components/About"));

// Simple Routing--
// // Main Component--
// const AppLayout = () => {
//     // Virtual DOM  => OBJECT --
//     // console.log(<Body />); // OBJECT
//     return (
//         <div className="app">
//             <Header />
//             <Body />
//         </div>
//     );
// };

// const appRouter = createBrowserRouter([
//     {
//         path: "/",
//         element: <AppLayout />,
//         errorElement: <Error />,
//     },
//     {
//         path: "/about",
//         element: <About />,
//     },
//     {
//         path: "/contact",
//         element: <Contact />,
//     },
// ]);

// Children Routing--
// Main Component--
const AppLayout = () => {
    // Authentication
    const [userName, setUserName] = useState();

    useEffect(() => {
        // Make API Call and send username and password.
        const data = {
            name: "Atharva Sugandhi",
        };
        setUserName(data.name);
    }, []);

    // Virtual DOM  => OBJECT --
    // console.log(<Body />); // OBJECT
    return (
        // Modify React Context Data--
        // All Places wrapped inside the UserContext takes the value of loggedInUser as Atharva.
        // setUserName is passed onto the UserContext which can be accessible from all over the component wrapped inside.
        <UserContext.Provider value={{ loggedInUser: userName, setUserName }}>
            <div className="app">
                <Header />
                {/* Outlet fills the element on which route it is present
            or we can say Outlet will be replaced by component */}
                <Outlet />
            </div>
        </UserContext.Provider>
    );
};

const appRouter = createBrowserRouter([
    {
        path: "/",
        element: <AppLayout />,
        children: [
            {
                path: "/",
                element: <Body />,
            },
            {
                path: "/about",
                element: (
                    <Suspense fallback={<Shimmer />}>
                        <About />
                    </Suspense>
                ),
            },
            {
                path: "/contact",
                element: <Contact />,
            },
            {
                path: "/grocery",
                element: (
                    <Suspense fallback={<Shimmer />}>
                        <Grocery />
                    </Suspense>
                ),
            },
            {
                // :resId is dynamic routing-
                path: "/restaurants/:resId",
                element: <RestaurantMenu />,
            },
        ],
        errorElement: <Error />,
    },
]);

const root = ReactDOM.createRoot(document.getElementById("root"));
// root.render(<AppLayout />);

root.render(<RouterProvider router={appRouter} />);
