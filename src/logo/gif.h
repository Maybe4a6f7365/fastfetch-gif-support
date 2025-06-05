#ifndef FASTFETCH_GIF_H
#define FASTFETCH_GIF_H

#include <stdbool.h>

typedef struct FFGifData FFGifData;

/**
 * Lädt eine GIF-Datei und gibt die GIF-Datenstruktur zurück.
 * @param path Pfad zur GIF-Datei
 * @return FFGifData* oder NULL bei Fehler
 */
FFGifData* ff_gif_load(const char* path);

/**
 * Prüft, ob das GIF animiert ist.
 * @param data GIF-Datenstruktur
 * @return true wenn animiert, sonst false
 */
bool ff_gif_is_animated(FFGifData* data);

/**
 * Gibt die Anzahl der Frames im GIF zurück.
 * @param data GIF-Datenstruktur
 * @return Anzahl der Frames oder 0 bei Fehler
 */
int ff_gif_get_frame_count(FFGifData* data);

/**
 * Gibt die Verzögerung für einen bestimmten Frame zurück.
 * @param data GIF-Datenstruktur
 * @param frame Frame-Index
 * @return Verzögerung in Millisekunden oder 0 bei Fehler
 */
int ff_gif_get_frame_delay(FFGifData* data, int frame);

/**
 * Gibt die Pixeldaten für einen bestimmten Frame zurück.
 * @param data GIF-Datenstruktur
 * @param frame Frame-Index
 * @param width Zeiger auf Variable für die Breite
 * @param height Zeiger auf Variable für die Höhe
 * @return RGB-Pixeldaten oder NULL bei Fehler
 */
unsigned char* ff_gif_get_frame_data(FFGifData* data, int frame, int* width, int* height);

/**
 * Gibt den Speicher der GIF-Datenstruktur frei.
 * @param data GIF-Datenstruktur
 */
void ff_gif_free(FFGifData* data);

#endif // FASTFETCH_GIF_H 