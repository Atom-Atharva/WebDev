import mongoose from "mongoose";

// For FruitsDB--
async function main() {
    //Connect to DB Server--
    // use `await mongoose.connect('mongodb://user:password@127.0.0.1:27017/test');` if your database has auth enabled
    await mongoose.connect("mongodb://127.0.0.1:27017/fruitsDB");

    //Creating Schema for Database--
    const fruitSchema = new mongoose.Schema({
        name: {
            type: String,
            required: true,
        },
        rating: {
            type: Number,
            min: 1,
            max: 5,
        },
        review: String,
    });

    //Declaring new fruit to schema--
    const Fruit = mongoose.model("Fruit", fruitSchema);

    //Create a new fruit--
    // const fruit = new Fruit({
    //     //If no name then its error--
    //     rating: 10, //Not Work As Its violets Validation--
    //     review: "Preety Solid Fruit!",
    // });

    //Create a new fruit--
    const fruit = new Fruit({
        name: "Apple",
        rating: 5,
        review: "Preety Solid Fruit!",
    });

    // Saving to database--(Comment when not in use)--
    // fruit.save();

    const kiwi = new Fruit({
        name: "Kiwi",
        rating: 3,
        review: "Not Available Easily :(",
    });
    const orange = new Fruit({
        name: "Orange",
        rating: 4,
        review: "Sour in Nature.",
    });
    // orange.save();

    const banana = new Fruit({
        name: "Banana",
        rating: 5,
        review: "Rich in Calcium!",
    });

    //Insert Many --
    // {ordered: true} prevent other entries to enter if once error occured--
    // Fruit.insertMany([kiwi, orange, banana], { ordered: true });

    // Finding All Elements--
    // console.log(await Fruit.find());

    //Update One element--
    // const res = await Fruit.updateOne({ name: "Grapes" }, { name: "Orange" });
    // console.log(res);

    // Delete One element--
    // const res = await Fruit.deleteOne({ name:"Orange" }); // returns {deletedCount: 1}
    // console.log(res);

    //Finding Only Name by FOREACH LOOP--
    const fruits = await Fruit.find();
    fruits.forEach((element) => {
        console.log(element.name);
    });

    //Creating Schema for Database--
    const personSchema = new mongoose.Schema({
        name: String,
        age: Number,
        favouriteFruit: fruitSchema,
    });

    //Declaring new person to schema--
    const Person = mongoose.model("Person", personSchema);

    //Create a new person--
    const person = new Person({
        name: "Atharva",
        age: 19,
    });

    const shaivi = new Person({
        name: "Shaivi",
        age: 15,
        favouriteFruit: orange,
    });

    // await shaivi.save();

    //Update Atharva--
    // const res = await Person.updateOne(
    //     { name: "Atharva" },
    //     { favouriteFruit: fruit }
    // );
    // console.log(res);

    //Saving to database--(Comment when not in use)--
    // await person.save();

    //Delete ONE--
    // const res = await Person.deleteOne({ name: "Shaivi" }); // returns {deletedCount: 1}
    // console.log(res);

    //Close the connection--
    mongoose.connection.close();
    mongoose.disconnect();
}

main().catch((err) => console.log(err));
