import React from "react";
import ReactDOM from "react-dom/client";
import Header from "./components/Header";
import Body from "./components/Body";
import About from "./components/About";
import Contact from "./components/Contact";
import { createBrowserRouter, RouterProvider, Outlet } from "react-router-dom";
import Error from "./components/Error";
import RestaurantMenu from "./components/RestaurantMenu";

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
    // Virtual DOM  => OBJECT --
    // console.log(<Body />); // OBJECT
    return (
        <div className="app">
            <Header />
            {/* Outlet fills the element on which route it is present
            or we can say Outlet will be replaced by component */}
            <Outlet />
        </div>
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
                element: <About />,
            },
            {
                path: "/contact",
                element: <Contact />,
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
