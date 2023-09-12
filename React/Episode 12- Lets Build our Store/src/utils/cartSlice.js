import { createSlice, current } from "@reduxjs/toolkit";

// Used to create a slice by using createSlice function which takes a configuration
const cartSlice = createSlice({
    name: "cart",
    // Initial Value for the states.
    initialState: {
        items: [],
    },
    // Use to modify the state.
    reducers: {
        // Add Element--
        // State: Refers to initialState...
        // Action: Function with some data...
        // This is a reducer function with name addItem which is mapped to action.
        addItem: (state, action) => {
            // Vanilla (Older) Redux: DON'T MUTATE STATE
            // const newState = [...state];
            // newState.items.push(action.payload);
            // return newState;

            // New Redux ToolKit
            // Mutating the state--
            // Same thing is done using "immer" library behind the scenes.
            state.items.push(action.payload);
        },
        // Remove the Top Element--
        removeItem: (state) => {
            state.items.pop();
        },
        clearCart: (state) => {
            // This will not mutate the state rather it just making reference
            // State is local variable.
            // state = ["Atharva"]; ---> Changing local variable

            // // This will console proxy state.
            // console.log(state);
            // // To avoid we use current from redux toolkit.
            // console.log(current(state));

            // Mutate the State.
            // state.items.length = 0; // []
            // OR
            // Return new Empty state replaces original state
            return { items: [] }; // []
        },
    },
});

// {
//     actions: {
//         addItem;
//     }
//     reducer;
// }

// Export actions
export const { addItem, removeItem, clearCart } = cartSlice.actions;

// Export Reducer(Combinations of all reducers functions) not reducers
export default cartSlice.reducer;
