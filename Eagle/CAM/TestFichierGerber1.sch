<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="9" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="1" fill="9" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Cartouche" color="15" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="1_TGE-sur G">
<description>Bibliothèque de base pour les élèves de première année en TGÉ.</description>
<packages>
<package name="CARTOUCHE">
<description>&lt;h1&gt;Cartouche TGÉ&lt;/h1&gt;</description>
<wire x1="0" y1="0" x2="0" y2="42.418" width="0.4064" layer="100"/>
<wire x1="0" y1="42.418" x2="0" y2="84.836" width="0.4064" layer="100"/>
<wire x1="0" y1="84.836" x2="0" y2="127.254" width="0.4064" layer="100"/>
<wire x1="0" y1="127.254" x2="0" y2="169.672" width="0.4064" layer="100"/>
<wire x1="0" y1="169.672" x2="0" y2="215.9" width="0.4064" layer="100"/>
<wire x1="0" y1="215.9" x2="49.022" y2="215.9" width="0.4064" layer="100"/>
<wire x1="49.022" y1="215.9" x2="94.488" y2="215.9" width="0.4064" layer="100"/>
<wire x1="94.488" y1="215.9" x2="139.7" y2="215.9" width="0.4064" layer="100"/>
<wire x1="139.7" y1="215.9" x2="184.912" y2="215.9" width="0.4064" layer="100"/>
<wire x1="184.912" y1="215.9" x2="229.87" y2="215.9" width="0.4064" layer="100"/>
<wire x1="229.87" y1="215.9" x2="279.4" y2="215.9" width="0.4064" layer="100"/>
<wire x1="279.4" y1="215.9" x2="279.4" y2="169.672" width="0.4064" layer="100"/>
<wire x1="279.4" y1="169.672" x2="279.4" y2="127.254" width="0.4064" layer="100"/>
<wire x1="279.4" y1="127.254" x2="279.4" y2="85.09" width="0.4064" layer="100"/>
<wire x1="279.4" y1="85.09" x2="279.4" y2="42.418" width="0.4064" layer="100"/>
<wire x1="279.4" y1="42.418" x2="279.4" y2="0" width="0.4064" layer="100"/>
<wire x1="279.4" y1="0" x2="275.59" y2="0" width="0.4064" layer="100"/>
<wire x1="275.59" y1="0" x2="3.81" y2="0" width="0.4064" layer="100"/>
<wire x1="3.81" y1="0" x2="0" y2="0" width="0.4064" layer="100"/>
<wire x1="0" y1="42.418" x2="3.81" y2="42.418" width="0.127" layer="100"/>
<wire x1="3.81" y1="42.418" x2="3.81" y2="0" width="0.127" layer="100"/>
<wire x1="0" y1="84.836" x2="3.81" y2="84.836" width="0.127" layer="100"/>
<wire x1="3.81" y1="84.836" x2="3.81" y2="42.418" width="0.127" layer="100"/>
<wire x1="0" y1="127.254" x2="3.81" y2="127.254" width="0.127" layer="100"/>
<wire x1="3.81" y1="127.254" x2="3.81" y2="84.836" width="0.127" layer="100"/>
<wire x1="0" y1="169.672" x2="3.81" y2="169.672" width="0.127" layer="100"/>
<wire x1="3.81" y1="169.672" x2="3.81" y2="127.254" width="0.127" layer="100"/>
<wire x1="3.81" y1="169.672" x2="3.81" y2="212.09" width="0.127" layer="100"/>
<wire x1="3.81" y1="212.09" x2="49.022" y2="212.09" width="0.127" layer="100"/>
<wire x1="49.022" y1="212.09" x2="49.022" y2="215.9" width="0.127" layer="100"/>
<wire x1="49.022" y1="212.09" x2="94.488" y2="212.09" width="0.127" layer="100"/>
<wire x1="94.488" y1="212.09" x2="94.488" y2="215.9" width="0.127" layer="100"/>
<wire x1="94.488" y1="212.09" x2="139.7" y2="212.09" width="0.127" layer="100"/>
<wire x1="139.7" y1="212.09" x2="139.7" y2="215.9" width="0.127" layer="100"/>
<wire x1="139.7" y1="212.09" x2="184.912" y2="212.09" width="0.127" layer="100"/>
<wire x1="184.912" y1="212.09" x2="184.912" y2="215.9" width="0.127" layer="100"/>
<wire x1="184.912" y1="212.09" x2="229.87" y2="212.09" width="0.127" layer="100"/>
<wire x1="229.87" y1="212.09" x2="275.59" y2="212.09" width="0.127" layer="100"/>
<wire x1="275.59" y1="169.672" x2="275.59" y2="212.09" width="0.127" layer="100"/>
<wire x1="275.59" y1="169.672" x2="279.4" y2="169.672" width="0.127" layer="100"/>
<wire x1="275.59" y1="127.254" x2="275.59" y2="169.672" width="0.127" layer="100"/>
<wire x1="275.59" y1="127.254" x2="279.4" y2="127.254" width="0.127" layer="100"/>
<wire x1="275.59" y1="85.09" x2="275.59" y2="127.254" width="0.127" layer="100"/>
<wire x1="275.59" y1="85.09" x2="279.4" y2="85.09" width="0.127" layer="100"/>
<wire x1="275.59" y1="42.418" x2="275.59" y2="85.09" width="0.127" layer="100"/>
<wire x1="275.59" y1="42.418" x2="279.4" y2="42.418" width="0.127" layer="100"/>
<wire x1="275.59" y1="0" x2="275.59" y2="42.418" width="0.127" layer="100"/>
<text x="1.27" y="193.04" size="2.1844" layer="100">A</text>
<text x="276.86" y="193.04" size="2.1844" layer="100">A</text>
<text x="276.86" y="147.32" size="2.1844" layer="100">B</text>
<text x="1.27" y="149.86" size="2.1844" layer="100">B</text>
<text x="1.27" y="106.68" size="2.1844" layer="100">C</text>
<text x="276.86" y="106.68" size="2.1844" layer="100">C</text>
<text x="276.86" y="63.5" size="2.1844" layer="100">D</text>
<text x="1.27" y="64.77" size="2.1844" layer="100">D</text>
<text x="1.27" y="21.59" size="2.1844" layer="100">E</text>
<text x="276.86" y="22.86" size="2.1844" layer="100">E</text>
<text x="23.876" y="213.106" size="2.1844" layer="100">1</text>
<text x="70.612" y="212.852" size="2.1844" layer="100">2</text>
<text x="116.586" y="213.106" size="2.1844" layer="100">3</text>
<text x="162.052" y="212.852" size="2.1844" layer="100">4</text>
<text x="206.502" y="212.852" size="2.1844" layer="100">5</text>
<text x="253.746" y="212.852" size="2.1844" layer="100">6</text>
<wire x1="229.87" y1="212.09" x2="229.87" y2="215.9" width="0.127" layer="100"/>
<wire x1="191.516" y1="35.814" x2="191.516" y2="28.194" width="0.127" layer="100"/>
<wire x1="191.516" y1="28.194" x2="191.516" y2="20.574" width="0.127" layer="100"/>
<wire x1="191.516" y1="20.574" x2="191.516" y2="12.954" width="0.127" layer="100"/>
<wire x1="191.516" y1="12.954" x2="191.516" y2="5.334" width="0.127" layer="100"/>
<wire x1="191.516" y1="5.334" x2="191.516" y2="0" width="0.127" layer="100"/>
<wire x1="191.516" y1="35.814" x2="219.456" y2="35.814" width="0.127" layer="100"/>
<wire x1="219.456" y1="35.814" x2="275.59" y2="35.814" width="0.127" layer="100"/>
<wire x1="191.516" y1="5.334" x2="198.374" y2="5.334" width="0.127" layer="100"/>
<wire x1="198.374" y1="5.334" x2="208.28" y2="5.334" width="0.127" layer="100"/>
<wire x1="208.28" y1="5.334" x2="219.456" y2="5.334" width="0.127" layer="100"/>
<wire x1="219.456" y1="5.334" x2="257.556" y2="5.334" width="0.127" layer="100"/>
<wire x1="257.556" y1="5.334" x2="275.59" y2="5.334" width="0.127" layer="100"/>
<wire x1="191.516" y1="12.954" x2="198.374" y2="12.954" width="0.127" layer="100"/>
<wire x1="198.374" y1="12.954" x2="275.59" y2="12.954" width="0.127" layer="100"/>
<wire x1="275.59" y1="20.574" x2="191.516" y2="20.574" width="0.127" layer="100"/>
<wire x1="219.456" y1="35.814" x2="219.456" y2="32.004" width="0.127" layer="100"/>
<wire x1="219.456" y1="32.004" x2="219.456" y2="5.334" width="0.127" layer="100"/>
<wire x1="191.516" y1="28.194" x2="219.456" y2="28.194" width="0.127" layer="100"/>
<wire x1="198.374" y1="12.954" x2="198.374" y2="5.334" width="0.127" layer="100"/>
<wire x1="208.28" y1="12.954" x2="208.28" y2="5.334" width="0.127" layer="100"/>
<wire x1="219.456" y1="32.004" x2="275.59" y2="32.004" width="0.127" layer="100"/>
<wire x1="275.59" y1="32.004" x2="275.59" y2="31.75" width="0.127" layer="21"/>
<wire x1="257.556" y1="5.334" x2="257.556" y2="0" width="0.127" layer="100"/>
<text x="192.532" y="34.036" size="1.27" layer="100">Dessiné par :</text>
<text x="192.532" y="26.416" size="1.27" layer="100">Vérifié par :</text>
<text x="192.532" y="18.542" size="1.27" layer="100">Approuvé par :</text>
<text x="192.278" y="11.176" size="1.27" layer="100">Format</text>
<text x="200.406" y="11.176" size="1.27" layer="100">Version</text>
<text x="210.82" y="10.922" size="1.27" layer="100">Révision</text>
<text x="193.04" y="2.54" size="1.27" layer="100">Date :</text>
<text x="259.08" y="2.54" size="1.27" layer="100">Feuille        de </text>
<text x="220.472" y="10.922" size="1.27" layer="100">Titre du shématique :</text>
<text x="220.218" y="18.288" size="1.27" layer="100">Chemin et nom du design:</text>
<text x="220.98" y="29.21" size="1.778" layer="100">CÉGEP de l'Outaouais</text>
<text x="220.98" y="26.67" size="1.4224" layer="100">820 Boulevard La Gappe</text>
<text x="220.98" y="24.13" size="1.4224" layer="100">Gatineau, Québec</text>
<text x="220.98" y="21.59" size="1.4224" layer="100">J8T 7T7</text>
<text x="199.39" y="30.48" size="1.6764" layer="100">Benoit Houle</text>
</package>
</packages>
<symbols>
<symbol name="CADRE_FORMAT_A">
<frame x1="0" y1="0" x2="279.4" y2="215.9" columns="6" rows="5" layer="100" border-bottom="no"/>
</symbol>
<symbol name="DOCUMENTATION">
<wire x1="0" y1="0" x2="66.04" y2="0" width="0.1016" layer="100"/>
<wire x1="66.04" y1="0" x2="84.074" y2="0" width="0.1016" layer="100"/>
<wire x1="84.074" y1="35.56" x2="27.94" y2="35.56" width="0.1016" layer="100"/>
<wire x1="27.94" y1="35.56" x2="0" y2="35.56" width="0.1016" layer="100"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.1016" layer="100"/>
<wire x1="0" y1="5.08" x2="0" y2="12.7" width="0.1016" layer="100"/>
<wire x1="0" y1="12.7" x2="0" y2="20.32" width="0.1016" layer="100"/>
<wire x1="0" y1="20.32" x2="0" y2="27.94" width="0.1016" layer="100"/>
<wire x1="0" y1="27.94" x2="0" y2="35.56" width="0.1016" layer="100"/>
<wire x1="84.074" y1="35.56" x2="84.074" y2="31.75" width="0.1016" layer="100"/>
<wire x1="84.074" y1="31.75" x2="84.074" y2="20.32" width="0.1016" layer="100"/>
<wire x1="84.074" y1="20.32" x2="84.074" y2="12.7" width="0.1016" layer="100"/>
<wire x1="84.074" y1="12.7" x2="84.074" y2="5.08" width="0.1016" layer="100"/>
<wire x1="84.074" y1="5.08" x2="84.074" y2="0" width="0.1016" layer="100"/>
<wire x1="27.94" y1="35.56" x2="27.94" y2="31.75" width="0.1016" layer="100"/>
<wire x1="27.94" y1="31.75" x2="27.94" y2="27.94" width="0.1016" layer="100"/>
<wire x1="27.94" y1="27.94" x2="27.94" y2="20.32" width="0.1016" layer="100"/>
<wire x1="0" y1="5.08" x2="6.858" y2="5.08" width="0.1016" layer="100"/>
<wire x1="6.858" y1="5.08" x2="16.764" y2="5.08" width="0.1016" layer="100"/>
<wire x1="16.764" y1="5.08" x2="27.94" y2="5.08" width="0.1016" layer="100"/>
<wire x1="27.94" y1="5.08" x2="66.04" y2="5.08" width="0.1016" layer="100"/>
<wire x1="66.04" y1="5.08" x2="84.074" y2="5.08" width="0.1016" layer="100"/>
<wire x1="0" y1="12.7" x2="6.858" y2="12.7" width="0.1016" layer="100"/>
<wire x1="6.858" y1="12.7" x2="16.764" y2="12.7" width="0.1016" layer="100"/>
<wire x1="0" y1="20.32" x2="27.94" y2="20.32" width="0.1016" layer="100"/>
<wire x1="0" y1="27.94" x2="27.94" y2="27.94" width="0.1016" layer="100"/>
<wire x1="6.858" y1="12.7" x2="6.858" y2="5.08" width="0.1016" layer="100"/>
<wire x1="16.764" y1="12.7" x2="84.074" y2="12.7" width="0.1016" layer="100"/>
<wire x1="16.764" y1="12.7" x2="16.764" y2="5.08" width="0.1016" layer="100"/>
<wire x1="27.94" y1="31.75" x2="84.074" y2="31.75" width="0.1016" layer="100"/>
<wire x1="27.94" y1="20.32" x2="84.074" y2="20.32" width="0.1016" layer="100"/>
<wire x1="27.94" y1="20.32" x2="27.94" y2="5.08" width="0.1016" layer="100"/>
<wire x1="66.04" y1="5.08" x2="66.04" y2="0" width="0.1016" layer="100"/>
<text x="7.366" y="1.778" size="2.54" layer="100" font="vector">&gt;LAST_DATE_TIME</text>
<text x="29.21" y="6.858" size="2.54" layer="100" font="vector">&gt;DRAWING_NAME</text>
<text x="28.702" y="28.702" size="2.1844" layer="100">CÉGEP de l'Outaouais</text>
<text x="28.702" y="26.162" size="1.778" layer="100">820 Boulevard La Gappe</text>
<text x="28.702" y="23.622" size="1.778" layer="100">Gatineau, Québec</text>
<text x="28.448" y="21.082" size="1.778" layer="100">J8T 7T7</text>
<text x="0.508" y="33.528" size="1.27" layer="100">Dessiné par:</text>
<text x="0.508" y="25.908" size="1.27" layer="100">Vérifié par:</text>
<text x="0.508" y="18.288" size="1.27" layer="100">Approuvé par:</text>
<text x="0.508" y="10.668" size="1.27" layer="100">Format</text>
<text x="8.89" y="10.668" size="1.27" layer="100">Version</text>
<text x="19.05" y="10.668" size="1.27" layer="100">Révision</text>
<text x="28.448" y="18.542" size="1.27" layer="100">Chemin et nom du design:</text>
<text x="28.448" y="10.922" size="1.27" layer="100">Titre du schématique:</text>
<text x="0.762" y="2.794" size="1.27" layer="100">Date:</text>
<text x="68.072" y="1.778" size="1.27" layer="100">Feuille(s)</text>
<text x="77.724" y="1.778" size="1.27" layer="100">de</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="CARTOUCHE_TGÉ" prefix="FRAME" uservalue="yes">
<description>&lt;b&gt;Cartouche de TGÉ: &lt;/b&gt; Grandeur A, dimention 8 1/2 x 11 pouces, orientation portrait.
&lt;p&gt;
Les élèves doivent utiliser la commande &lt;b&gt;TEXT&lt;/b&gt; pour placer les valeurs aux champs appropriés.&lt;p&gt;
&lt;b&gt;Couche  100 Cartouche, ne pas oublier de créer cette couche!&lt;/b&gt;&lt;p&gt;
&lt;b&gt;Size par défaut: 0,07&lt;/b&gt; ou ajusté en conséquence si pas asez d'espace.&lt;p&gt;
&lt;b&gt;Ratio:&lt;/b&gt; 8%&lt;p&gt;
&lt;b&gt;Font:&lt;/b&gt; Vector.&lt;p&gt;
Voir la commande TEXT pour plus d'information.</description>
<gates>
<gate name="G$1" symbol="CADRE_FORMAT_A" x="0" y="0" addlevel="always"/>
<gate name="G$2" symbol="DOCUMENTATION" x="191.516" y="0.254" addlevel="always"/>
</gates>
<devices>
<device name="" package="CARTOUCHE">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="FRAME1" library="1_TGE-sur G" deviceset="CARTOUCHE_TGÉ" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="FRAME1" gate="G$1" x="0" y="0" smashed="yes"/>
<instance part="FRAME1" gate="G$2" x="191.516" y="0.254" smashed="yes">
<attribute name="LAST_DATE_TIME" x="198.882" y="2.032" size="2.54" layer="100" font="vector"/>
<attribute name="DRAWING_NAME" x="220.726" y="7.112" size="2.54" layer="100" font="vector"/>
</instance>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
