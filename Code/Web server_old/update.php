<!DOCTYPE html>
<html>
   <head>
      <meta charset="utf-8" />
      <link rel="stylesheet" type="text/css" href= "main.php" />
      <title>Projet Syntèse</title>
   </head>
   <body>
     <?php
     $MiseAJour = "/Gerber/MiseAJour";
     $MessageUrgent = "";
     $ProgressBarPourcent = "1";
     $ProgressBarOperation = "x/x";

     $FichierOuvert = fopen($MiseAJour, "r");

      if (FALSE === $FichierOuvert)
      {
        $ProgressBarOperation = "Erreur";
        $ProgressBarPourcent  = "Erreur";
      }
      else
      {
        $ProgressBarOperation = fgets($FichierOuvert);
        $ProgressBarPourcent  = fgets($FichierOuvert);

        fclose($FichierOuvert);
      }

       if(isset($_POST['ArretUrgence']))
       {
          exec('./bin/kill programme');
          $MessageUrgent = "Arret d'urgence effectuer.";
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
               <p class="ccc"><span class="sideh2"> Projet syntèse de mes études au cegep de l'Outaouais</span><br /><br />Pour mon projet final, j'ai du modifier une vieille machine CNC pour pouvoir l'utiliser comme un graveur de circuit imprimé (PCB).<br /><br />
                 Pour réussir,  j'ai du refaire l'alimentation au complet, un nouveau système de contrôle des moteurs, un serveur web (cette page) et un programme pour générer un chaine de commande pour contrôler les moteurs à partir d'un fichier Gerber.
               </p>
            </aside>
            <!-- end .sidebar1 -->
         </div>
         <!-- menu -->
         <article class="content">
            <h1>Mise a jour</h1>
               <section>
                  <h2>File d'attente</h2>
                  <button onclick="Actualiser()">Actualiser</button>

                  <label><?php echo  $ProgressBarOperation ?></label>
                  <div id="Progress">
                    <div id="ProgressBar" ><?php echo $ProgressBarPourcent ?>%</div>
                  </div>

                  <h2>Arret d'urgence</h2>
                  <form method="post">
                    <input type="submit" name="ArretUrgence" value="Arret d'urgence"/>
                  </form>
                  <br />
                  <p><?php echo $MessageUrgent ?></p>
               </section>
               <!-- end .content -->
         </article>
         <!-- content -->
         <footer>
            <div class="footerright">
               <p> Programmation web <br />2015 <br />Adapté pour mon projet <br />syntèse en génie électrique<br />2020<br /> <a href="http://www.cegepoutaouais.qc.ca/" title="Site du Cégep de l'Outaqouais">Cégep de l'Outaouais</a><br /><span class="chose">Benoit Houle <br /> benoithoulep@gmail.com <br /> (819) 918-9059 </span>
               </p>
            </div>
            <address>
               &copy; benoithoule.com
            </address>
         </footer>
         <!-- end .container -->
      </div>
      <script>
      function Actualiser()
      {
        var elem = document.getElementById("ProgressBar");
        var width = <?php echo $ProgressBarPourcent; ?>;
        elem.style.width = width + "%";
      }
      </script>
   </body>
</html>
