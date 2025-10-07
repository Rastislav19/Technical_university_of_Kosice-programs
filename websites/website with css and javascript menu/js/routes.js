import Mustache from "./mustache.js";
import processOpnFrmData from "./addOpinion.js";

//an array, defining the routes
export default[

    {
        //the part after '#' in the url (so-called fragment):
        hash:"welcome",
        ///id of the target html element:
        target:"router-view",
        //the function that returns content to be rendered to the target html element:
        getTemplate:(targetElm) =>
            document.getElementById(targetElm).innerHTML = document.getElementById("template-welcome").innerHTML
    },
    {
        hash:"articles",
        target:"router-view",
        getTemplate: fetchAndDisplayArticles
    },
    {
        hash:"opinions",
        target:"router-view",
        getTemplate: createHtml4opinions
    },
    {
        hash:"addOpinion",
        target:"router-view",
        getTemplate: (targetElm) =>{
            document.getElementById(targetElm).innerHTML = document.getElementById("template-addOpinion").innerHTML;
            document.getElementById("opnFrm").onsubmit=processOpnFrmData;
        }
    }

];

function createHtml4opinions(targetElm){
    const opinionsFromStorage=localStorage.myTreesComments;
    let opinions=[];

    if(opinionsFromStorage){
        opinions=JSON.parse(opinionsFromStorage);
        opinions.forEach(opinion => {
            opinion.created = (new Date(opinion.created)).toDateString();
        });
    }

    document.getElementById(targetElm).innerHTML = Mustache.render(
        document.getElementById("template-opinions").innerHTML,
        opinions
    );
}

function fetchAndDisplayArticles(targetElm){
    const url = "https://wt.kpi.fei.tuke.sk/api/article";

    function reqListener () {
        // stiahnuty text
        console.log(this.responseText)
        if (this.status == 200) {
            document.getElementById(targetElm).innerHTML =
                Mustache.render(
                    document.getElementById("template-articles").innerHTML,
                    JSON.parse(this.responseText)
                );
        } else {
            alert("Došlo k chybe: " + this.statusText);
        }

    }
    console.log(url)
    var ajax = new XMLHttpRequest();
    ajax.addEventListener("load", reqListener);
    ajax.open("GET", url, true);
    ajax.send();
    console.log("send")

    /*
    current=parseInt(current);
    totalCount=parseInt(totalCount);
    const data4rendering={
        currPage:current,
        pageCount:totalCount
    };

    if(current>1){
        data4rendering.prevPage=current-1;
    }

    if(current<totalCount){
        data4rendering.nextPage=current+1;
    }

    document.getElementById(targetElm).innerHTML = Mustache.render(
        document.getElementById("template-articles").innerHTML,
        data4rendering
    );


    /*
        return `<h1>Main Content</h1>
                ${current} <br>
                ${totalCount} <br>
                ${JSON.stringify(data4rendering)}
                `;
    */


}