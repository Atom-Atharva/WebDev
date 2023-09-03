import User from "./User";
import UserClass from "./UserClass";
import { Component } from "react";

// Class Based Component--
class About extends Component {
    constructor(props) {
        super(props);

        console.log("Parent Constructor!");
    }

    // Called After the component is completely mounted into the page.
    componentDidMount() {
        console.log("Parent ComponentDidMount");

        // Same as useEffect()
        // It is used to make API calls.
    }

    render() {
        console.log("Parent Render!");

        return (
            <div>
                <h1>About</h1>
                <h2>This is Atom!</h2>
                {/* <User /> */}
                {/* <UserClass /> */}

                {/* PROPS */}
                {/* <User name={"Atharva Sugandhi (Function)"} /> */}
                <UserClass
                    name={"Atharva Sugandhi (Class)"}
                    location={"Indore (Class)"}
                />
                {/* <UserClass
                    name={"Second (Class)"}
                    location={"Indore (Class)"}
                />
                <UserClass name={"Third (Class)"} location={"Indore (Class)"} /> */}
            </div>
        );
    }
}

// Functional Component--
// const About = () => {
//     return (
//         <div>
//             <h1>About</h1>
//             <h2>This is Atom!</h2>
//             {/* <User /> */}
//             {/* <UserClass /> */}

//             {/* PROPS */}
//             {/* <User name={"Atharva Sugandhi (Function)"} /> */}
//             <UserClass
//                 name={"Atharva Sugandhi (Class)"}
//                 location={"Indore (Class)"}
//             />
//         </div>
//     );
// };

export default About;
