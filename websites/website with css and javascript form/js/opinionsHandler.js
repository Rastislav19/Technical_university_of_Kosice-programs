/*Class for  handling a list (an array) of visitor opinions in local storage
The list is filled from a form and rendered to html
A template literal is used to render the opinions list
*/
export default class OpinionsHandler {

    //constructor
    // @param opinionsFormElmId - id of a form element where a new visitor opinion is entered
    // @param opinionsListElmId - id of a html element to which the list of visitor opinions is rendered

    constructor(opinionsFormElmId, opinionsListElmId) { //("opnFrm","opinionsContainer")
        this.opinions = [];

        //TODO Add opinionsElm property, referencing the div with id given by the parameter opinionsListElmId
        this.opinionsElm = document.getElementById(opinionsListElmId);
        //TODO Add opinionsFrmElm property, referencing the form with id given by the parameter opinionsFormElmId
        this.opinionsFrmElm = document.getElementById("opinion-form");
    }

    // initialisation of the list of visitor opinions and form submit setup
    init() {
        if (window.localStorage.opinionComments) {
            this.opinions = JSON.parse(window.localStorage.opinionComments);
        }

        //TODO render opinions to html
        this.opinionsElm.innerHTML = this.opinionArray2html(this.opinions);


        this.opinionsFrmElm.addEventListener("submit", event => this.processOpnFrmData(event));
    }

    /*
    Processing of the form data with a new visitor opinion
    @param event - event object, used to prevent normal event (form sending) processing
    */
    processOpnFrmData(event) {
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
        //if ( document.getElementById("yes").value == "on") {
        //  nopHuman = "YES";
        //}
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

        //console.log("New opinion:\n "+JSON.stringify(newOpinion));

        opinions.push(newOpinion);

        window.localStorage.opinionComments = JSON.stringify(opinions);

        //console.log(opinions);

        //5. Reset the form
        this.opinionsFrmElm.reset();//resets the form


    }

    /*
    creates html code for one opinion using a template literal
    @param opinion - object with the opinion
    @returns {string} - html code with the opinion
    */
    opinion2html(opinion) {
        //TODO finish opinion2html
        const opinionTemplate =
            `
			    <section>
			    <h3>${opinion.name} <i>(${(new Date(opinion.created)).toDateString()})</i></h3>
                <p><b>email:</b> ${opinion.email}</p>
			    <p>${opinion.image}</p>
			    <p><b>prvá preferencia:</b> ${opinion.preference1}</p>
			    <p><b>druhá preferencia:</b> ${opinion.preference2}</p>
			    <p><b>kľúčové slovo:</b> ${opinion.keywords}</p>
			    <p><b>Komentár:</b> ${opinion.opinion}</p>
			    </section>`;
        return opinionTemplate;
    }

    /*
    creates html code for all opinions in an array using the opinion2html method
    @param sourceData -  an array of visitor opinions
    @returns {string} - html code with all the opinions
    */
    opinionArray2html(sourceData) {
        //TODO finish opinionArray2html
        return sourceData.reduce((htmlWithOpinions, opn) => htmlWithOpinions + this.opinion2html(opn), "");
    }
}





