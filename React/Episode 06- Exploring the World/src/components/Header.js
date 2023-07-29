import { LOGO_URL } from "../utils/constants";
import { useState } from "react";

// Header Component--
const Header = () => {
    // Normal Variable--
    // let btnName = "Login";

    // Special Local State Variable--
    // const variable is not updating it is re-rendering every time thus a new variable is made.
    const [btnNameReact, setBtnNameReact] = useState("Login");

    return (
        <div className="header">
            <div className="logo-container">
                <img src={LOGO_URL}></img>
            </div>
            <div className="nav-items">
                <ul>
                    <li>Home</li>
                    <li>About Us</li>
                    <li>Contact Us</li>
                    <li>Cart</li>
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
                </ul>
            </div>
        </div>
    );
};

// Export Header Component--
export default Header;
