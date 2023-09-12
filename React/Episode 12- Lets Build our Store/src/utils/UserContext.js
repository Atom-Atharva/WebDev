// Function by react to create React Context
import { createContext } from "react";

// Global Data which can be accessed from anywhere.
const UserContext = createContext({
    loggedInUser: "Default User",
});

export default UserContext;
