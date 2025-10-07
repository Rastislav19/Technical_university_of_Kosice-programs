export default function processOpnFrmData(event){
    //1.prevent normal event (form sending) processing
    event.preventDefault();

    //2. Read and adjust data from the form (here we remove white spaces before and after the strings)
    const nopName = document.getElementById("name").value.trim();
    const nopOpinion = document.getElementById("opinion").value.trim();
    const nopEmail = document.getElementById("email").value.trim();
    const nopImage = document.getElementById("image").value.trim();
    let nopPreference1 = "No data";
    let nopPreference2 = "No data";
    const nopHuman1 = document.getElementById("yes").value;
    const nopHuman2 = document.getElementById("yes2").value;
    let nopKeywords = document.getElementById("keyWords").value;

    if (document.getElementById("cat").checked) {
        nopPreference1 = document.getElementById("cat").value;
    }
    if (document.getElementById("dog").checked) {
        nopPreference1 = document.getElementById("dog").value;
    }
    if (document.getElementById("hamster").checked) {
        nopPreference2 = document.getElementById("hamster").value;
    }
    if (document.getElementById("mouse").checked) {
        nopPreference2 = document.getElementById("mouse").value;
    }

    //3. Add the data to the array opinions and local storage
    const newOpinion =
        {
            name: nopName,
            email: nopEmail,
            image: nopImage,
            preference1: nopPreference1,
            preference2: nopPreference2,
            human1: nopHuman1,
            human2: nopHuman2,
            opinion: nopOpinion,
            keywords: nopKeywords,
            created: new Date()

        };


    let opinions = [];

    if(localStorage.myTreesComments){
        opinions=JSON.parse(localStorage.myTreesComments);
    }

    opinions.push(newOpinion);
    localStorage.myTreesComments = JSON.stringify(opinions);


    //5. Go to the opinions
    window.location.hash="#opinions";

}

