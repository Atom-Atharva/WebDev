import { LOGO_URL } from "../utils/constants";
import { useState, useEffect, useContext } from "react";
import { Link } from "react-router-dom";
import useOnlineStatus from "../utils/useOnlineStatus";
import UserContext from "../utils/UserContext";

// Header Component--
const Header = () => {
    // Normal Variable--
    // let btnName = "Login";

    // Special Local State Variable--
    // const variable is not updating it is re-rendering every time thus a new variable is made.
    const [btnNameReact, setBtnNameReact] = useState("Login");
    console.log("Header Rendered!");

    const onlineStatus = useOnlineStatus();

    // No Dependency Array --> useEffect Calls on Every Render.
    // Empty Dependency Array --> useEffect Called on Initial Render only once.
    // Dependency Array --> [btnNameReact] --> useEffect Called Every time btnNameReact Changes.
    useEffect(() => {
        console.log("UseEffect Called!");
    }, [btnNameReact]);

    // To Access the Global React Context from UserContext file we use a Hook useContext.
    const { loggedInUser } = useContext(UserContext);
    // console.log(data);

    return (
        <div className="header flex justify-between bg-pink-100 shadow-lg mb-2 sm:bg-yellow-50 lg:bg-green-50">
            <div className="w-36 logo-container">
                <img src={LOGO_URL}></img>
            </div>
            <div className="nav-items flex items-center">
                <ul className="flex m-4 p-4">
                    {/* Reusability of OnlineStatus Custom Hook */}
                    <li className="px-4">
                        ONLINE STATUS: {onlineStatus ? "🟢" : "🔴"}
                    </li>

                    <li className="px-4">
                        <Link to="/">Home</Link>
                    </li>
                    <li className="px-4">
                        {/* <a href="/about">About Us</a> */}
                        <Link to="/about">About Us</Link>
                    </li>
                    <li className="px-4">
                        <Link to="/contact">Contact Us</Link>
                    </li>
                    <li className="px-4">
                        <Link to="/grocery">Grocery</Link>
                    </li>
                    <li className="px-4">Cart</li>
                    <button
                        className="login"
                        onClick={() => {
                            // btnName = "Logout";
                            if (btnNameReact === "Login") {
                                setBtnNameReact("Logout");
                            } else {
                                setBtnNameReact("Login");
                            }
                        }}
                    >
                        {btnNameReact}
                    </button>
                    <li className="px-4 font-bold">{loggedInUser}</li>
                </ul>
            </div>
        </div>
    );
};

// Export Header Component--
export default Header;
