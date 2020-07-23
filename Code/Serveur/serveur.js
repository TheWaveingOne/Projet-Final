const express = require('express')
const app = express()
const formidable = require('formidable')

var fs = require('fs');
var path = require('path');
var {execSync} = require('child_process');

app.use(express.static(path.join(__dirname, '/')));


//-----------------------
//Déclaration de variable et constante
//-----------------------
function AjouterDessin(Chaine, name) {
  this.EtapeActuel = 0;
  this.EtapeTotal = Chaine.length;
  this.name = name;
  this.ChaineDeCommandes = Chaine;
}
var FileAttenteDessins = [];
var DessinEnCour = 0;



//-----------------------
//Demande de page web
//-----------------------
app.get('/projet', function(req, res){
  console.log('/projet ---------------------------------------------------')
  res.sendFile('/Gerber/projet.html');
});

app.get('/update', function(req, res){
  console.log('/update -----------------------------------------------------')
  res.sendFile('/Gerber/update.html');
});

app.get('/adduser', function(req, res){
  console.log('/AjouterUtilisateur ---------------------------------------------------')
  res.sendFile('/Gerber/ajouterutilisateur.html');
});

//-----------------------
//Crée un utilisateur
//-----------------------
app.post('/Gerber/addnewuser', (req, res) => {
  console.log('Cree un utilisateur ------------------------------------------------')

  var Username = '';
  var Password = '';
  var PageARetourner = '';
  var FormData = new formidable.IncomingForm();

  res.writeHead(200, {'Content-Type': 'text/html'})

  FormData.parse(req, function(err, fields, files) {
      if (err) {
        console.error(err.message);
        return;
      }

      Username = fields.Username;
      Password = fields.Password;

      var Path = "/Gerber/Users/" + Username + "." + Password;
      console.log('Compte crée: ' + Path)

      fs.open(Path, 'w', function (err, file) {
        if (err)
        {
          PageARetourner =+ "<h2>" + err + "</h2>"

          console.log("error: " + err)
          res.write(PageARetourner)

          console.log('end')
          res.end()
        }
        else
        {
          PageARetourner += "<h2>Compte Crée</h2><p>Nom : " + Username + "</p><p>Mot de passe : " + Username + "</p>";

          res.write(PageARetourner)

          console.log('end')
          res.end()
        }
      });
    });
})

//-----------------------
//Traiter la demande de mise a jour.
//-----------------------
app.post('/Gerber/miseajour', (req, res) => {
  console.log('Demande de mise a jour -----------------------------------------------')

  var PageARetourner = '';
  res.writeHead(200, {'Content-Type': 'text/html'})

  var NombreDeDessin = (FileAttenteDessins.length - 1);
  console.log('Nombre De Dessin = ' + NombreDeDessin)


  if (NombreDeDessin >= 0) {

    var Commande = 'echo "' + FileAttenteDessins[DessinEnCour].ChaineDeCommandes[FileAttenteDessins[DessinEnCour].EtapeActuel] + '" > /dev/ttyS1';

    if (FileAttenteDessins[DessinEnCour].EtapeActuel >= FileAttenteDessins[DessinEnCour].EtapeTotal) {
      DessinEnCour += 1;
    }

    FileAttenteDessins[DessinEnCour].EtapeActuel += 1;

    console.log('Commande: ' + Commande)

    execSync(Commande, {});

    var i;
    for( i = 0; i <= NombreDeDessin; i++)
    {
      PageARetourner += '<label>' + FileAttenteDessins[i].name + ', ' + FileAttenteDessins[i].EtapeActuel + '/' + FileAttenteDessins[i].EtapeTotal + '</label><br />';
      PageARetourner += '<progress value="' + FileAttenteDessins[i].EtapeActuel + '" max="' + FileAttenteDessins[i].EtapeTotal + '" style="width:100%;" ></progress><br /><br />';
    }
  } else {
    PageARetourner = "<p>Il n'y a aucun dessin a faire.</p>";
  }

  res.write(PageARetourner)

  console.log('end')
  res.end()
})

//-----------------------
//Gérer un ficher.
//-----------------------
app.post('/Gerber/upload', (req, res) => {
  console.log('Nouveau ficher --------------------------------------------------')
  var RetourErreur = '<h2>Erreur</h2>';

  var Username = '';
  var Password = '';
  var Path = '';

  new formidable.IncomingForm().parse(req)

    .on('field', (name, field) => {
      if (name == 'Username') {
        if (field.length > 0) {
          Username = field;
        }
        else {
          Username = "b";
        }
      }
      if (name == 'Password') {
        if (field.length > 0) {
          Password = field;
        }
        else {
          Password = "b";
        }
      }
      Path = "/Gerber/Users/" + Username + "." + Password;
    })

    .on('fileBegin', (name, file) => {

      res.writeHead(200, {'Content-Type': 'text/html'})

      if (file.name.length > 0) {
            file.path = '/Gerber/' + file.name;
      }
      else {
            file.path = '/Gerber/Erreur';
            RetourErreur += '<p>Erreur dans le nom du fichier.</p>';
      }

    })
    .on('file', (name, file) => {

      if (fs.existsSync(Path)) {
        var Commande = "/Gerber/traductionfichiergerber " + file.name;
        var RetourBinaire = execSync(Commande, {});
        var RetourString = RetourBinaire.toString('utf8');
        var Commandes = RetourString.split("\n");

        if (Commandes.length > 1) {

              FileAttenteDessins.push(new AjouterDessin(Commandes, file.name));

              var NombreDeDessin = (FileAttenteDessins.length - 1);

              console.log('FileAttenteDessins[X].ChaineDeCommandes:')
              console.log(FileAttenteDessins[NombreDeDessin].ChaineDeCommandes)
              console.log('Nom du dessin: ' + FileAttenteDessins[NombreDeDessin].name)
              console.log('Nombre De Dessin total: ' + NombreDeDessin)

              RetourErreur = RetourErreur + '<p>Aucune erreur, fichier valide.</p>' + '<p>Vérifier la file d\'attente pour voir la progression de votre dessin.</p>';

        } else {
              console.log('Erreur: ' + RetourString)
              RetourErreur = RetourErreur + RetourString + '';
        }
        res.write(RetourErreur)
      } else {
        res.write("Mauvais nom d'utilisateur et/ou mot de passe.")
        console.log("Mauvais nom d'utilisateur et/ou mot de passe.")
      }
    })
    .on('error', (err) => {
      console.error('Error', err)
    })
//-----------------------
//Finir le traitement du ficher.
//-----------------------
    .on('end', () => {
      console.error('end')
      res.end()
    })
})

//-----------------------
//Démarer le serveur
//-----------------------
app.listen(3000, () => {
  console.log('Server started localhost:3000');
});
