
function listOfAnimals(data, start, count){
    try { 
        if(isNaN(start) || isNaN(count)) throw "not a number";
        if(start < 0) throw "Cannot be less than zero";
        if(start > data.length -1) throw "cannot be great than list";
    }
    catch(err) {
        return '<div>Error: ' + err + '</div>';
    }
    var list = [];
    for(var i = start; i < count +start; i++){
        list.push(data[i]);
    }
    return (list.length > 0) ? list : '<p>No items</p>';
}

function detailOfAnimal(data, id){
    var animal = {};
    try{
        if(isNaN(id)) throw "Argument is not a number";
        if(id < 0) throw "Cannot be less than zero";
        if(id > data.length -1) throw "cannot be great than list";
        var i = 0;
        while(i < data.length || !animal){
            if(data[i].id == id) animal = data[i];
            i++;
        }
    }catch(err){
        return '<div>Error: ' +err + '</div>';
    }
    return animal;
}

console.log(detailOfAnimal(json, 50));



$(function(){
    var animals = [];
    var animal = {};

    function listView(start, count){
        animals = listOfAnimals(json, start, count);
        animal = animals[0];
        $('#list').html('<div class="list-group"></div>');
        animals.forEach(function(item, index){
            $('#list .list-group').append('<a href = "#" data-id="'+ item.id +'" class="list-group-item">'+item.title+'</a>');
        });
        itemClick();
    }

    function detailView(animal){
        $('#detail').html('<h3>'+ animal.title +'</h3> <h5>'+animal.latin_title+'</h5> <table><tr><td>Třída</td><td>'+animal.classes.title+'</td></tr> </table>'

    )}

    function itemClick(){
        $('#list .list-group-item').on('click', function(){
            animal = detailOfAnimal(json, $(this).data('id'));
            console.log(animal);
            detailView(animal);
        });
    }

    listView(0, 11);
    detailView(animal);
});