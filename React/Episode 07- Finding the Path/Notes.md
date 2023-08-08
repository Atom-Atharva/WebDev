# Episode: 07 Notes

## Note-

-   Whenever a function starts with use, it denotes it is a hook (Common Convention for HOOKs).

## useEffect Hook

-   Contains callback function, and dependency array.
-   When useEffect is Called:
    -   Every-time the component is rendered useEffect is called.
    -   Dependency Array changes behavior of its call-
        1. No dependency array: Call on every Render.
        2. If dependency array is empty: Call on only initial Render and just once.
        3. If dependency array is [prop]: Called every time prop changes.

## useState Hook

-   Never Create useState variable outside of the component.
-   Because it is used to create local state variable inside your functional component.
-   Create these on top of component.
-   Never create these variables inside if-else, for-loop, functions. This can create inconsistency in app.

## Routing in React

-   npm install react-router-dom

-   createBrowserRouter : This helps our app to deal with no. of routes, check app.js

-   RouterProvider : This will provide routing configuration to our app.

-   On false route : react-router-dom creates an error page for you.

-   We can also make our error page using error element see app.js.

-   useRouteError : Using this hook we can get more info about error (SEE Error.js).

-   Children Routing : Load children according to path. (Certain component is to be loaded see app.js)

-   To Load children route inside component we use OUTLET.(SEE app.js)

-   Outlet is like a tunnel in which all children go in place of outlet.

-   IN REACT: Never Ever Use a anchor tag to route to some other page, because the whole page will get refreshed.

-   A superpower given by react-router-dom is known as LINK which helps us to route to some other page without reload our page. see header.js

-   Link component works same as anchor tag.

-   This is why React applications are known as SINGLE PAGE APPLICATIONS.

## Two Type of Routings

1. Client Side Routing: Not network calls needed, all components are already loaded and on calling it just load that specific component.
2. Server Side Routing: About.html coming from server, network calls are made.

## Dynamic Routing

-   Loading Dynamic Content inside our app. (See app.js)
-   To read the dynamic route we can use useParams HOOK.(See RestaurantCard.js)

## Clickable Restaurant Cards

-   See app.js
-   Connected to LINK component.
-   Behind the scenes LINK is using Anchor Tag (Check Dev Console).
