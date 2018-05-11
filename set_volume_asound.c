#include <alsa/asoundlib.h>
#include <alsa/mixer.h>
#include <unistd.h>
void SetAlsaMasterVolume(long volume)
{
    long min, max;
    int lvol=0, rvol=0, maxvol=70;

    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    const char *card = "default";
    const char *selem_name = "Line";

    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
    printf("min=%i, max=%i\n", min, max);
//    snd_mixer_selem_set_playback_volume_all(elem, volume * max / 100);
    snd_mixer_selem_set_playback_volume(elem, SND_MIXER_SCHN_FRONT_LEFT, maxvol * max / 100);
    snd_mixer_selem_set_playback_volume(elem, SND_MIXER_SCHN_FRONT_RIGHT, maxvol * max / 100);
    for (rvol=0;rvol<maxvol;rvol++) {
        usleep(100000);
        snd_mixer_selem_set_playback_volume(elem, SND_MIXER_SCHN_FRONT_RIGHT, rvol * max / 100);
    }
    for (lvol=maxvol;lvol>=0;lvol--) {
        usleep(100000);
        snd_mixer_selem_set_playback_volume(elem, SND_MIXER_SCHN_FRONT_LEFT, lvol * max / 100);
    }
    snd_mixer_selem_set_playback_volume(elem, SND_MIXER_SCHN_FRONT_LEFT, maxvol * max / 100);
    snd_mixer_selem_set_playback_volume(elem, SND_MIXER_SCHN_FRONT_RIGHT, maxvol * max / 100);
    snd_mixer_close(handle);
}

int main(int argc, char **argv)
{
  SetAlsaMasterVolume(60);
  return 0;
}
