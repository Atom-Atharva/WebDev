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
