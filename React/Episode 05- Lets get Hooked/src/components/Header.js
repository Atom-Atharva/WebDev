import { LOGO_URL } from "../utils/constants";

// Header Component--
const Header = () => {
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
                </ul>
            </div>
        </div>
    );
};

// Export Header Component--
export default Header;
