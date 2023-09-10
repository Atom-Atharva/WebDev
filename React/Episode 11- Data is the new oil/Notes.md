# Episode 11: Data is the new Oil

## Higher Order Component

-   It is a normal JS function.

-   It is a function which takes a component and returns a component.

-   It acts like a enhance the function, which takes component, modifies the component and return it back (See RestaurantCard.js and Body.js).

## React with UI and DATA

-   UI Layer is very static

-   React Application has 2 layers:

    -   UI Layer.
    -   Data Layer.

-   UI layer is powered by Data layer.

-   Data Layer consist of all the states, props, local variables whereas UI layer consist of JSX.

## Accordion

-   Drop Down Menu (See RestaurantMenu.js).

## Controlled and Uncontrolled Environment & LIFTING THE STATE UP

-   When a component decides and controlling itself then it is uncontrolled element. (RestaurantCategory --> RestaurantCategory)

-   When a parent element controls the child then this is known as controlled environment. (RestaurantMenu --> RestaurantCategory) : This is known as LIFTING STATE UP.

## Props Drilling

-   Data Flows from higher level to lower level components.

-   Data cannot skip any intermediate node.

-   This is not good way to pass data along the hierarchy (accepted 2 levels).

-   To solve this problem we have React Context.

## React Context

-   Data is the new oil, so the data should not be flowed to much, for this we have react context.

-   Global Data which can be used from anywhere in application.(See UserContext.js)

-   We use HOOKS like createContext for creating the global data and useContext to access from anywhere.(See App.js About.js Body.js)

-   Context Provider: Set value in React Context.

-   Context Consumer: Access Value from React Context.

-   If the Context Provider is wrapped it must passed a value else it will generate error.

-   For Default Value you don't need to wrapped with Context Provider
