# Episode 12:

## REDUX

-   Redux is used to create its own store.

-   Redux works in the data layer and UI layer and Data layer works in sync to create its own app.

-   Redux handles the data in our application.

-   Redux is not mandatory in our application.

-   Redux offer easy debugging.

-   Libraries we are using are:
    1. Redux Toolkit (RTK): Standard way to write Redux Logic.
    2. React-Redux: Bridge between react and redux.

## Redux Toolkit

-   It is a global place where all our state and local data exists, which can be accessible from anywhere inside our application.

-   It is okay to store everything inside our Redux Store, for this we have slices inside our redux store.

-   Slice of Redux Store is a small portion of our redux store. We can make different slices for different category of data.

-   We cannot directly modify these slices, we need to follow certain steps:

    1. Dispatch (Action): Calls a Function.
    2. Reducer (Function): Modifies the Data inside slice.

-   Example:
    When we click ADD BUTTON ---> It dispatches an action ---> Calls the reducer function ---> Modifies the Cart Slice in Redux Store.

-   We cannot read data directly, we need to use selector, selector is used to read data from the slice and selector will modify our react component. This process is known as "SUBSCRIBING TO THE STORE".

-   Example:
    Header Component is subscribed to the redux store using selector, used to remain synced with the store.

![Redux-Working](./Screenshots/Redux%20Working.png)

## Redux Toolkit & React-Redux STEPS:

1. Install @reduxjs/toolkit and react-redux

2. Build our own Store (SEE appStore.js)

3. Connect our store to our App (SEE app.js)

4. Create a Slice (Cart Slice)(SEE cartSlice.js)

5. Dispatch (Action) (SEE ItemList.js)

6. Selector (See Header.js)

## Important things to remember

-   Whenever you are doing selector make sure you are subscribing to right portion of the store. (TO OPTIMIZE THE PERFORMANCE) (SEE Cart.js)

-   Make sure you are writing correct thing: reducers in slices (contain many reducer functions)(but exported as reducer(combination of small reducers function))and reducer in main appStore (contain many small reducers).

-   In Older Redux: DON'T MUTATE STATE and RETURN IS MANDATORY rather make copy of state and push it inside new state and return new state.

-   In New Redux Toolkit: We have to MUTATE State.

-   Redux DevTools make developer's life easy in debugging.

# Assignment:

## useContext vs Redux

-   useContext: useContext is a hook that provides a way to pass data through the component tree without manually passing props down through each nested component.

-   Redux: Redux is a state managing library used in JavaScript apps. It is very popular for React and React-Native. It simply manages the state and data of your application.

-   Building Parts of redux:

    1. Action
    2. Reducer
    3. Store

-   (Differences between Redux and useContext)[https://www.geeksforgeeks.org/whats-the-difference-between-usecontext-and-redux/]

## Redux Toolkit over Redux

-   Redux Toolkit is used to write redux code but in more concise way, RTK abstracts the basic redux code and provides us boilerplate that enable us to write redux code in less line of code.

-   RTK reduces complexity of the Redux.
-   RTK gives ability to write mutable state updates in the reducers.

## Dispatcher

-   Dispatcher dispatches an action and trigger state changes to the store.

## Reducer

-   Pure functions that contain the logic and calculation that needed to be performed on the state.

## Slice

-   Small portion of the redux store.

-   Collection of Redux reducer logic and actions for a single feature in your app, typically defined together in a single file.

## Selector

-   It is used to SUBSCRIBING to the store, on updating the state --> updates should reflect on the components which are subscribed to the store using selector.

## createSlice

-   This function is used to create slice in our store.

-   It takes:

    1. initial State
    2. Object of Reducer Functions
    3. Slice Name

-   It automatically generates action creators and action types that correspond to the reducers and state.
