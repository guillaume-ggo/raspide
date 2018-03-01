# raspide
Rassemble le code, la documentation lié au projet raspide
# Projet Raspide
## Objectif

Mettre au point une solution plus légeère et réduire l'encombrement du matériel d'aide au pilotage de machines sportives pilotées par un non voyant.

# Mise en place

## Pré-requis

* Disposer d'un raspberry (ici la version 3 est utilisée)
* disposer d'une carte son (TODO trouver la référence)


## Installation du système

* Télécharger le système léger à [cet adresse](https://downloads.raspberrypi.org/raspbian_lite_latest)
* Configurer l'accès SSH et le wi-fi avec une adresse IP statique [à l'aide de ce lien](https://raspbian-france.fr/raspberry-pi-sans-ecran-sans-clavier/)
**NOTE**: Le fichier à modifier est `/etc/dhcpcd.conf`
# Commandes utiles
* Lister les cartes sons disponibles:

```
aplay -l
```

* Lire un fichier WAV sur une autre carte son que celle par défaut:

```
aplay -Ddefault:1 <fichier>
```

* Activer l'entrée ligne de la carte son:

```
amixer -c 1 sset Line,0 80% 80% unmute cap
```

* Changer la source audio de la carte son:

```
#Adapter le nom des contrôles en invoquant d'abord amixer
amixer -c1 cset iface=MIXER,name='PCM Capture Source' 'Line'
```

* Enregistrer un son:

```
arecord -f cd -d 5 /tmp/test.wav
```


# Liens utiles
* [Installation de la librairie ASound](https://raspberrypi.stackexchange.com/questions/13171/how-to-get-alsa-lib-on-raspbian)
* [Projet utilisant la librairie ASound](https://gist.github.com/ghedo/963382)
* [Documentation sur la librairie ASound](https://www.alsa-project.org/alsa-doc/alsa-lib/pcm.html)
* [Le site du projet ALSA](http://www.alsa-project.org/main/index.php/SoundcardTesting)
* [La liste des raccourcis braille implémentés dans BRLTTY](http://mielke.cc/brltty/doc/KeyBindings/brl-eu-esys_medium.html)
* [Mixer l'entrée micro et l'entrée ligne](https://raspberrypi.stackexchange.com/questions/56278/possible-to-route-audio-directly-from-usb-audio-line-in-to-same-usb-audio-line-o)
