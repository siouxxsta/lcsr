
#pragma once

#if defined LCSR_DEBUG
	#define DEBUGMENU
	#define CHATTYSPLASH
	#define TIMEBARS
	#define RELOADABLES
	#define MISSION_SWITCHER
	#define USE_DEBUG_SCRIPT_LOADER
	#define SCRIPT_LOG_FILE_LEVEL 2
	#define LOAD_INI_SETTINGS
#elif defined LSCR_MASTER
	#define SCRIPT_LOG_FILE_LEVEL 0
#endif

#define DRAW_GAME_VERSION_TEXT
#ifdef DRAW_GAME_VERSION_TEXT
	// Unlike R* development builds, ours has runtime switch on debug menu & .ini, and disabled as default.
	// If you disable this then game will fetch version from peds.col, as R* did while in development.
	#undef USE_OUR_VERSIONING
#endif

// Use faster method of string comparisons.
#define ASCII_STRCMP

enum Config {
	NUMPLAYERS = 1,

	NUMCDIMAGES = 6,
	MAX_CDIMAGES = 8,
	MAX_CDCHANNELS = 5,

	MODELINFOSIZE = 6500,
	TXDSTORESIZE = 1385,
	COLSTORESIZE = 31,
	EXTRADIRSIZE = 256,
	CUTSCENEDIRSIZE = 512,

	SIMPLEMODELSIZE = 3885,
	TIMEMODELSIZE = 385,
	CLUMPMODELSIZE = 5,
	WEAPONMODELSIZE = 37,
	PEDMODELSIZE = 130,
	VEHICLEMODELSIZE = 110,
	TWODFXSIZE = 1210,

	MAXVEHICLESLOADED = 70,

	NUMOBJECTINFO = 210,

	// Pool sizes
	NUMPTRNODES = 50000,
	NUMENTRYINFOS = 3200,
	NUMPEDS = 140,
	NUMVEHICLES = 110,
	NUMBUILDINGS = 7000,
	NUMTREADABLES = 1,
	NUMOBJECTS = 460,
	NUMDUMMIES = 2340,
	NUMAUDIOSCRIPTOBJECTS = 192,
	NUMCOLMODELS = 4400,
	NUMCUTSCENEOBJECTS = 50,

	NUMANIMBLOCKS = 35,
	NUMANIMATIONS = 450,

	NUMTEMPOBJECTS = 40,

	// Path data
	NUM_PATHNODES = 9650,
	NUM_CARPATHLINKS = 3500,
	NUM_MAPOBJECTS = 1250,
	NUM_PATHCONNECTIONS = 20400,

	// Link list lengths
	NUMALPHALIST = 20,
	NUMBOATALPHALIST = 20,
	NUMALPHAENTITYLIST = 200,
	NUMALPHAUNTERWATERENTITYLIST = 30,
	NUMCOLCACHELINKS = 50,
	NUMREFERENCES = 800,

	// Zones
	NUMAUDIOZONES = 14,
	NUMINFOZONES = 169,
	NUMMAPZONES = 39,
	NUMNAVIGZONES = 20,

	// Cull zones
	NUMATTRIBZONES = 704,

	NUMOCCLUSIONVOLUMES = 350,
	NUMACTIVEOCCLUDERS = 48,

	PATHNODESIZE = 4500,

	NUMWEATHERS = 7,
	NUMHOURS = 24,

	NUMEXTRADIRECTIONALS = 4,
	NUMANTENNAS = 8,
	NUMCORONAS = 56,
	NUMPOINTLIGHTS = 32,
	NUM3DMARKERS = 32,
	NUMBRIGHTLIGHTS = 32,
	NUMSHINYTEXTS = 32,
	NUMMONEYMESSAGES = 16,
	NUMPICKUPMESSAGES = 16,
	NUMBULLETTRACES = 16,
	NUMMBLURSTREAKS = 4,
	NUMSKIDMARKS = 32,

	NUMONSCREENCLOCKS = 1,
	NUMONSCREENCOUNTERS = 3,
	NUMRADARBLIPS = 75,
	NUMGENERALPICKUPS = 320,
	NUMSCRIPTEDPICKUPS = 16,
	NUMPICKUPS = NUMGENERALPICKUPS + NUMSCRIPTEDPICKUPS,
	NUMCOLLECTEDPICKUPS = 20,
	NUMPACMANPICKUPS = 256,
	NUMEVENTS = 64,

	NUM_CARGENS = 185,

	NUM_PATH_NODES_IN_AUTOPILOT = 8,

	NUM_ACCIDENTS = 20,
	NUM_FIRES = 40,
	NUM_GARAGES = 32,
	NUM_PROJECTILES = 32,

	NUM_GLASSPANES = 45,
	NUM_GLASSENTITIES = 32,
	NUM_WATERCANNONS = 3,

	NUMPEDROUTES = 200,
	NUMPHONES = 50,
	NUMPEDGROUPS = 67,
	NUMMODELSPERPEDGROUP = 16,
	MAXZONEPEDSLOADED = 8,
	NUMSHOTINFOS = 100,

	NUMROADBLOCKS = 300,
	NUM_SCRIPT_ROADBLOCKS = 16,

	NUMVISIBLEENTITIES = 2000,
	NUMINVISIBLEENTITIES = 150,

	NUM_AUDIOENTITY_EVENTS = 4,
	NUM_PED_COMMENTS_SLOTS = 20,

	NUM_SOUND_QUEUES = 2,
	NUM_AUDIOENTITIES = 250,

	NUM_SCRIPT_MAX_ENTITIES = 40,

	NUM_GARAGE_STORED_CARS = 4,

	NUM_CRANES = 8,
	NUM_ESCALATORS = 22,
	NUM_WATER_CREATURES = 8,

	NUM_EXPLOSIONS = 48,

	NUM_SETPIECES = 96,
	NUM_SHORTCUT_START_POINTS = 16
};

// We don't expect to compile for PS2 or Xbox, but it might be interesting for documentation purposes.
// #define GTA_PS2
// #define GTA_XBOX
#define GTA_PC

// Version defines
// #define GTAVC_PS2		( 400 )
// #define GTAVC_PC_10		( 410 )
// #define GTAVC_PC_JAP		( 412 )
#define GTAVC_PC_11			( 411 )
#define GTA_VERSION			( GTAVC_PC_11 )

// Pad
#if !defined(RW_GL3) && defined(_WIN32)
#define XINPUT
#endif
#if defined XINPUT || (defined RW_GL3 && !defined LIBRW_SDL2 && !defined GTA_HANDHELD)
#define DETECT_JOYSTICK_MENU // Then we'll expect user to enter Controller->Detect joysticks if his joystick isn't detected at the start.
#endif
#define DETECT_PAD_INPUT_SWITCH // Adds automatic switch of pad related stuff between controller and kb/m
#define KANGAROO_CHEAT
#define RESTORE_ALLCARSHELI_CHEAT
#define BETTER_ALLCARSAREDODO_CHEAT
#define WALLCLIMB_CHEAT
#define REGISTER_START_BUTTON
#define BIND_VEHICLE_FIREWEAPON // Adds ability to rebind fire key for 'in vehicle' controls
#define BUTTON_ICONS            // use textures to show controller buttons

// Default build options for us.
#if defined GTA_PC
	#define GTA_PS2_STUFF
	#define GTA3_STEAM_PATCH
	#define GTAVC_JP_PATCH

	#define PC_MENU
	#define PC_WATER

	#define GTA_REPLAY
	#define GTA_SCENE_EDIT
	
	// Audio features.
	#define EXTERNAL_3D_SOUND
	#define AUDIO_REVERB
	#define AUDIO_REFLECTIONS
	#define RADIO_SCROLL_TO_PREV_STATION
	#define AUDIO_CACHE
	#define AUDIO_OAL_USE_SNDFILE
	#define AUDIO_OAL_USE_MPG123
	#define MULTITHREADED_AUDIO

	// Sounds would follow ped and vehicles coordinates.
	#define ATTACH_RELEASING_SOUNDS_TO_ENTITIES
	
	// Slows down or speeds up sounds according to the speed of the game itself.
	#define USE_TIME_SCALE_FOR_AUDIO

	#define PC_PLAYER_CONTROLS
	#define THIS_IS_STUPID
	#define DONT_FIX_REPLAY_BUGS
	#define USE_TXD_CDIMAGE
	#define ANIM_COMPRESSION
	#define COMPRESSED_COL_VECTORS
	#define USE_BETA_REPLAY_MODE

	// This allows us changing structs while keeping saves compatible, and keeps saves compatible between platforms.
	#define COMPATIBLE_SAVES
	#define FIX_INCOMPATIBLE_SAVES
	#define VALIDATE_SAVE_SIZE

	// Use onscreen despawn range for offscreen entities to avoid them despawning when you look away.
	#define EXTENDED_OFFSCREEN_DESPAWN_RANGE

	// Enable mission replay from Mobile port.
	#define MISSION_REPLAY
	
	// Rendering, display options.
	#define FIX_SPRITES
	#define FIX_RADAR
	#define RADIO_OFF_TEXT
	#define ASPECT_RATIO_SCALE
	#define PROPER_SCALING
	#define IMPROVED_VIDEOMODE
	#define ANISOTROPIC_FILTERING
	#define USE_CUTSCENE_SHADOW_FOR_PED
	
	// Menu enchancements.
	// Adding waypoint and better mouse support
	#define MAP_ENHANCEMENTS

	#define TRIANGLE_BACK_BUTTON
	#define CIRCLE_BACK_BUTTON
	#define LEGACY_MENU_OPTIONS
	#define XBOX_MESSAGE_SCREEN
	#define CUSTOM_FRONTEND_OPTIONS
	
	// Emulating PS2 alpha testing.
	#define PS2_ALPHA_TEST

	// Vehicle behaviours.
	#define EXPLODING_AIRTRAIN
	#define CPLANE_ROTORS

	// Pickups.
	#define MONEY_MESSAGES
	#define CAMERA_PICKUP

	// Peds.
	#define CANCELLABLE_CAR_ENTER
	
	// Camera.
	#define IMPROVED_CAMERA
	#define FREE_CAM
	
	// Enables use of larger *.IMG files.
	#define BIG_IMG
#endif

// Enabling some PS2 features.
#if defined GTA_PS2_STUFF
	#define USE_PS2_RAND
	#define PS2_MATFX
	#define PS2_AUDIO_CHANNELS
	#define PS2_AUDIO_PATHS
	#define RANDOMSPLASH
	#define VU_COLLISION
#endif

// Use enchancements from aap's librw.
#if defined LIBRW
	#define EXTENDED_COLOURFILTER
	#define EXTENDED_PIPELINES
	#define SCREEN_DROPLETS
	#define NEW_RENDERER
#endif

// Enables specific options and behaviours of game menu.
#ifdef CUSTOM_FRONTEND_OPTIONS
	#define GRAPHICS_MENU_OPTIONS
	#define NO_ISLAND_LOADING
	#define CUTSCENE_BORDERS_SWITCH
	#define MULTISAMPLING
	#define INVERT_LOOK_FOR_PAD
	#define PED_CAR_DENSITY_SLIDERS
#endif

// Fixes bugs that I encountered during development/reversing. (and were not fixed!)
#define FIX_BUGS
#define FIX_BUGS_64

// Skips audio CD check.
#define NO_CDCHECK

// Set default video mode to native resolution of a host. (fixes Windows 10 launch process)
#define DEFAULT_NATIVE_RESOLUTION

// Enables "Nasty game" for all available languages.
#define NASTY_GAME

// Script stuff.
#define USE_MEASUREMENTS_IN_METERS
#define USE_PRECISE_MEASUREMENT_CONVERTION
#define USE_MISSION_REPLAY_OVERRIDE_FOR_NON_MOBILE_SCRIPT
#define SUPPORT_MOBILE_SCRIPT
#define SUPPORT_GINPUT_SCRIPT

// Dummy protection.
#if (defined SUPPORT_XBOX_SCRIPT && defined SUPPORT_MOBILE_SCRIPT)
	static_assert(false, "SUPPORT_XBOX_SCRIPT and SUPPORT_MOBILE_SCRIPT are mutually exclusive");
#endif

#if (defined LCSR_DEBUG && defined LCSR_MASTER)
	static_assert(false, "LCSR_DEBUG and LCSR_MASTER are mutually exclusive");
#endif

#if (defined GTA_PC && defined GTA_PS2 || defined GTA_XBOX)
	static_assert(false, "LCSR_DEBUG and LCSR_MASTER are mutually exclusive");
#endif