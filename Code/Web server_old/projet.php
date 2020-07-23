<!DOCTYPE html>
<html>
   <head>
      <meta charset="utf-8" />
      <link rel="stylesheet" type="text/css" href= "main.php" />
      <title>Projet Syntèse</title>
   </head>
   <body>
      <?php

      function LireFichier($NomDuFichier)
      {
        $FichierALire = fopen($NomDuFichier, "r");

        if (FALSE === $FichierALire)
        {
          return "<p>Erreur lors de l'obtention de cette information.</p>";
        }
        $ContenuFichier = fread($FichierALire, filesize($NomDuFichier));

        fclose($FichierALire);
        return $ContenuFichier;
      }

      $ErreurDepot = "";
      $FichierErreur         = "/Gerber/Erreur";
      $FichierAvertissement  = "/Gerber/Avertissement";
      $Erreur           = "Nécéssite l'évaluation d'un fichier.";
      $Avertissement    = "Nécéssite l'évaluation d'un fichier.";

         //Largement inspiré de : https://www.w3schools.com/php/php_file_upload.asp
         if ($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['submit'])) {

             $target_dir  = "/Gerber/";
             $target_file = $target_dir . "Gerber"; 
             $uploadOk    = 1;

             if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
                 $ErreurDepot = "Le fichier " . basename($_FILES["fileToUpload"]["name"]) . " a été téléversé.";
             } else {
                 $ErreurDepot = "Desoler, il y a eu un probleme lors du téléversement du fichier.";
             }
             exec ('/Gerber/programme');

            $Erreur           = LireFichier($FichierErreur);
            $Avertissement    = LireFichier($FichierAvertissement);
         }

      ?>

      <div class="container">
         <header>
            <span class="name">Machine CNC</span>
         </header>
         <div class="sidebar1">
            <!-- menu -->
            <ul class="nav">
               <li class="navcouleur">
                  <a href="projet.php">Mon fichier</a>
                  <ul class="sousliste">
                     <li>Déposer le fichier</li>
                     <li>Erreur</li>
                  </ul>
               </li>
               <li>
                  <a href="update.php">Mise à jour</a>
                  <ul class="sousliste">
                     <li>File d'attente</li>
                     <li>Progrès du dessin</li>
                  </ul>
               </li>
            </ul>
            <aside>
               <p class="ccc"><span class="sideh2"> Projet syntèse de mes études au cegep de l'Outaouais</span> Pour mon projet final, j'ai du modifier une vieille machine CNC pour pouvoir l'utiliser comme un graveur de circuit imprimé (PCB). Pour réussir,  j'ai du refaire l'alimentation au complet,
                  un nouveau système de contrôle des moteurs, un serveur web (cette page) et un programme pour générer un chaine de commande pour contrôler les moteurs à partir d'un fichier Gerber.
               </p>
            </aside>
            <!-- end .sidebar1 -->
         </div>
         <!-- menu -->
         <article class="content">
            <h1>Depot du fichier gerber</h1>
            <section>
               <h2>Depot</h2>
               <form action="projet.php" method="post" enctype="multipart/form-data">
                  Sélectionner le fichier:
                  <input type="file" name="fileToUpload" id="fileToUpload"><br><br>
                  <input type="submit" value="Upload Gerber" name="submit">
               </form>
               <p><?php echo $ErreurDepot ?></p>
               <h2>Erreur</h2>
               <p><?php echo $Erreur ?>
               </p>
               <h2>Avertissement</h2>
               <p><?php echo $Avertissement ?>
               </p>
            </section>
            <!-- end .content -->
         </article>
         <!-- content -->
         <footer>
            <div class="footerright">
               <p> Programmation web 2015 <br /> <a href="http://www.cegepoutaouais.qc.ca/" title="Site du Cégep de l'Outaqouais">Cégep de l'Outaouais</a><br /><span class="chose">Benoit Houle <br /> benoithoulep@gmail.com <br /> (819) 918-9059 </span>
               </p>
            </div>
            <address>
               &copy; benoithoule.com
            </address>
         </footer>
         <!-- end .container -->
      </div>
   </body>
</html>
