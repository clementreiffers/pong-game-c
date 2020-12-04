#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define WAV_PATH "bass.wav"
#define MUS_PATH "bass.wav"

// Our wave file
Mix_Chunk *wave = NULL;
// Our music file
Mix_Music *music = NULL;


int main(int argc, char* argv[]){

	// Initialize SDL.
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return -1;
			
	//Initialize SDL_mixer 
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) 
		return -1; 
	
	// Load our sound effect
	wave = Mix_LoadWAV(WAV_PATH);
	if (wave == NULL)
		return -1;
	
	// Load our music
	music = Mix_LoadMUS(MUS_PATH);
	if (music == NULL)
		return -1;
	
	if ( Mix_PlayChannel(-1, wave, 0) == -1 )
		return -1;
	
	if ( Mix_PlayMusic( music, -1) == -1 )
		return -1;
		
	while ( Mix_PlayingMusic() ) ;
	
	// clean up our resources
	Mix_FreeChunk(wave);
	Mix_FreeMusic(music);
	
	// quit SDL_mixer
	Mix_CloseAudio();
	
	return 0;
}