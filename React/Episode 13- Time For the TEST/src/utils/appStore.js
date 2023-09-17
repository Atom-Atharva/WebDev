import { configureStore } from "@reduxjs/toolkit";
import cartReducer from "./cartSlice";

const appStore = configureStore({
    // Each Slice will have its own reducer--
    // Contain many reducers.
    reducer: {
        cart: cartReducer,
        // user: userReducer, 
    },
});

export default appStore;
