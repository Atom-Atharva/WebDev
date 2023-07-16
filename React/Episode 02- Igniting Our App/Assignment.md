# Episode 02 Assignment:

## NPM

-   NPM doesn't stand for anything.
-   NPM manages all the Packages in our app.

## Parcel/Webpack

-   Code Bundler which is used mostly for JavaScript or TypeScript code that helps you to minify, clean and make your code compact so that it becomes easier to send or receive the response from the server when it usually takes you to transfer multiple files without using any bundler for loading the page of your applications.

## Parcel-cache

-   This file stores the info in the cache memory to prevent re-loading of web page again and again.
-   Makes app faster.

## NPX

-   It stands for Node Package eXecute.
-   NPX is used for execute the package without even installing it.
-   For example - `npx parcel index.html`

## Dependencies And Dev-Dependencies

-   Dependencies are of 2 types-
    1. Normal Dependencies - Used in production of our app.
    2. DevDependencies - Used in creation of our app.

## Tree Shaking

-   Statically analyzes the imports and exports of each module and removes everything that isn't used.
-   Property of parcel.

## Hot Module Replacement

-   When ever there is a change in the code, parcel automatically updates your code in the browser, no page reload necessary!

## Parcel Super-Powers

1. Caching - Saves time of installing and analyzing again and again.
2. HMR
3. Tree Shaking
4. Dev Server - Provides you the facility of Server for the development purposes.
5. Diagnostics - On spotting the error, parcel displays beautiful diagnostics in your terminal and in the browser.

-   [FOR MORE DETAILS](https://parceljs.org/)

## Gitignore

-   It is a type of file which is used to prevent unwanted or secret files to not push to github servers.
-   We should add files which are sensitive to developer or site which is not meant to be showcasing to all other people and files which can be recreated using json and packages. (For Eg- package_module, secrets.txt, parcel-cache).

## Package json & Package-lock json

-   package.json store the approximate versions of the dependencies.
-   package-lock.json stores the info of exact versions of the dependencies.

## Package-lock json

-   package-lock.json contains exact information about dependencies, touching it will be very dangerous.

## Node_Module

-   It is the folder containing packages, which are used for development and functioning of the app.
-   It contain the dependencies and transitive dependencies which are already mentioned in the json file which is used to recreate files so no need to push it in git.

## Dist

-   It contains the compressed form of the codes to be pushed in production.
-   It is created by using build keyword in the command.
-   For Eq `npx parcel build index.html`

## Browserslist

-   It helps us to make our app compatible to certain browsers.

```
"browserslist": [
    "last 2 versions"
]
```

## (^)Caret and (~)Tilde

-   In json file ^ on dependency means it can be upgraded to minor upgrades automatically.
-   In json file ~ on dependency means it can be upgraded to major upgrades automatically.

## Script Types in HTML

-   There are 3 types of scripts in HTML:
    1. Inline Script: Inside HTML tag itself
    2. Internal Script: Inside HTML File
    3. External Script: Dedicated JavaScript File.
