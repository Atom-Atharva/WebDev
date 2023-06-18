import { MongoClient, ServerApiVersion } from "mongodb";

// Replace the placeholder with your Atlas connection string
const uri = "mongodb://127.0.0.1:27017";

// Create a MongoClient with a MongoClientOptions object to set the Stable API version
const client = new MongoClient(uri, {
    serverApi: {
        version: ServerApiVersion.v1,
        strict: true,
        deprecationErrors: true,
    },
});

//Check for connnection--
// async function run() {
//     try {
//         // Connect the client to the server (optional starting in v4.7)
//         await client.connect();

//         // Send a ping to confirm a successful connection
//         await client.db("admin").command({ ping: 1 });
//         console.log(
//             "Pinged your deployment. You successfully connected to MongoDB!"
//         );
//     } finally {
//         // Ensures that the client will close when you finish/error
//         await client.close();
//     }
// }
// run().catch(console.dir);

//InsertMany in Database--
// async function run() {
//     try {
//         const database = client.db("fruitsDB");
//         const fruits = database.collection("fruits");

//         // create an array of documents to insert
//         const docs = [
//             { name: "Apple", score: 8, review: "Great Fruit" },
//             { name: "Orange", score: 6, review: "Sour Fruit" },
//             { name: "Banana", score: 9, review: "Contains Calcium" },
//         ];

//         // this option prevents additional documents from being inserted if one fails
//         const options = { ordered: true };

//         const result = await fruits.insertMany(docs, options);
//         console.log(`${result.insertedCount} documents were inserted`);
//     } finally {
//         await client.close();
//     }
// }
// run().catch(console.dir);

//Find Multiple Documents--
async function run() {
    try {
        const database = client.db("fruitsDB");
        const movies = database.collection("fruits");

        //Find using query and options
        // query for movies that have a runtime less than 15 minutes
        //   const query = { runtime: { $lt: 15 } };
        // const options = {
        //     // sort returned documents in ascending order by title (A->Z)
        //     sort: { title: 1 },
        //     // Include only the `title` and `imdb` fields in each returned document
        //     projection: { _id: 0, title: 1, imdb: 1 },
        // };
        // const cursor = movies.find(query, options);

        const cursor = movies.find();

        // print a message if no documents were found
        if ((await movies.countDocuments()) === 0) {
            console.log("No documents found!");
        }

        for await (const doc of cursor) {
            console.dir(doc);
        }
    } finally {
        await client.close();
    }
}
run().catch(console.dir);
