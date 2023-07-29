# Episode 06: Exploring the World

## Monolith Architecture

-   Doing everything inside the same project.
-   Same language throughout the project.

## Micro-service Architecture

-   Doing everything separately and combine together to forms a big app.
-   This is known as separation of concerns and single responsibility principal.
-   This services contact each other by via connections.
-   Any service can be written in any language.
-   This services can be deployed on different port.
-   And these ports can be mapped onto same domain name.
-   In this episode we will learn how to connect to these services and fetch the data.

## Connections to outside world

-   As we are using mock data from the file we created in utils, we now need the data from outside world (Dynamic Data).
-   Two Approaches to fetch the data from backend are:
    1. Page Loads --> Api call --> Render UI.
    2. Page Loads --> Render it! --> Api Call --> Render the data.
-   React uses the 2nd Approach ---> Better UX (User Experience).

## useEffect Hooks

-   It is a normal JS function.
-   Similar to useState it is also called to app using named import.
-   Syntax ---> useEffect(callback function, dependency array).
-   Callback function will be called when the page is completely rendered.

## Fetching the data.

-   With the help of fetch function (Given by browsers)

-   Swiggy API can be seen from developer console in NETWORKS

-   Can we use directly any api inside fetch function?

    -   No, fetching data from API to local host has been blocked using CORS policy.

    -   CORS stands for Cross Origin Resource Sharing, browsers don't allow API to call from local host, i.e, from one origin to another origin.

    -   To avoid this we need to use chrome extension allow CORS.

-   SEE BODY fetchData() function, setting list of restaurant is not good way by copying path to restaurant list, rather we can use optional chaining for paths(JavaScript Concept).

-   Optional Chaining `(?.)` : When a path is called and it doesn't exist, then rather than throwing an error it will show NULL or Undefined.

-   As we know the page is first rendering Loading... and then Api call is done and data is populated inside the App.

-   It is not the good way to use Loading... rather use SHIMMER UI.

-   SHIMMER UI: Latest Technology, It is a fake UI which tells how the page will looks like on populating.

-   Conditional Rendering: When we are rendering on some condition.

## Header Button LOGIN/LOGOUT-

-   On using normal variable and on changing it will not re-render our web-page, thus we need to use local state variable.
-   This special local state variable changes then react re-render the page.
-   Actually it will re-render the whole Header Component.
-   const state variable is re-rendered every time it is updated thus creating new variable every time thus const properties remain unaffected.
-   This is known as Reconciliation Algorithm (DIFFERENCE IS UPDATED!!) which makes react fast!!

## Search Bar

-   On typing anything inside txt box bonded with state variable, body will render again and again.
-   Whenever state variable updates, react triggers a reconciliation cycle(Re-renders the component).
-   toLowerCase() & includes().
-   FilteredRestaurant list is made to preserve the main list of restaurants.

## CODE FAST, SLOW DEBUGGING! CODE SLOW, NO DEBUGGING!!

- BY: MASTER AKSHAY SAINI