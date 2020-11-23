window.onclick = function(e) {
    var id = e.target.id;
    if (id === 'sent') {
        var txt = document.getElementById('example').value;
        txt = document.createTextNode(txt);
        var ptag = document.createElement("p");
        ptag.appendChild(txt);

        var tag = document.createElement("div");
        tag.className = "container_individual";
        tag.appendChild(ptag);
        $("#comment").append(tag);
    }
}