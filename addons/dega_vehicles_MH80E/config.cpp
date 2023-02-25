class Components;
class ViewPilot;
class MainTurret;
class Turrets;
class CopilotTurret;
class AnimationSources;
class CargoTurret;
class CfgPatches 
{
	class DEGA_Vehicles_MH80E 
	{
		units[] = 
		{
		    "DEGA_B_Heli_Transport_01_dynamicLoadout_F"		
		};
		weapons[] = {};
		requiredVersion = 0.01;
		requiredAddons[] = {"A3_Air_F_Beta", "A3_Data_F_Heli"};
	};
};
class Mod_Base;
class CfgMods 
{
	class DEGA_Nato : Mod_Base 
	{
        //#include "\dega_vehicles_ah99\data\release\mod.cpp"
	};
};	
class SensorTemplatePassiveRadar;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class CfgVehicles
{
	class B_Heli_Transport_01_F;
	class DEGA_B_Heli_Transport_01_dynamicLoadout_F : B_Heli_Transport_01_F
	{	
		author="Deltagamer";	
		editorPreview = "";
		transportSoldier = 4;	
		_generalMacro="DEGA_Heli_Transport_01_dynamicLoadout_F";
		scope = 2;
		icon="\A3\Air_F_Beta\Heli_Transport_01\Data\UI\map_heli_transport_01_armed_ca.paa";
		picture="\A3\Air_F_Beta\Heli_Transport_01\Data\UI\heli_transport_01_armed_ca.paa";		
		scopeCurator = 2;
		scopeArsenal = 2;
		forceInGarage=1;
		displayName="MH-80E Shadow Hawk";
		side=1;
		faction="BLU_F";
		crew="B_Helipilot_F";
		typicalCargo[]={"B_pilot_F"};
		accuracy=2.5;
		selectionFireAnim="";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};	
		hiddenSelectionsTextures[]=
		{
			"\A3\Air_F_Beta\Heli_Transport_01\Data\Heli_Transport_01_ext01_CO.paa",
			"\A3\Air_F_Beta\Heli_Transport_01\Data\Heli_Transport_01_ext02_CO.paa"
		};		
		weapons[]=
		{
			"DEGA_LMG_Minigun_Transport" // LMG_Minigun_Transport LMG_Minigun_Transport2
		};
		magazines[]=
		{
			"DEGA_4000Rnd_65x39_Belt_Tracer_Red" //  2000Rnd_65x39_Belt_Tracer_Red
		};	
		memoryPointGun[]=
		{
			"muzzle_beg",
			"muzzle_beg_2"
		};
		gunBeg[]=
		{
			"muzzle_beg",
			"muzzle_beg_2"
		};
		gunEnd[]=
		{
			"muzzle_end",
			"muzzle_end_2"
		};			
		class AnimationSources: AnimationSources
		{
			class Door_L
			{
				source="door";
				animPeriod=1.6;
				initPhase=0;
				displayName = "Door (Left)"; 
				author = "Deltagamer"; 				
			};
			class Door_R: Door_L
			{
				displayName = "Door (Right)"; 
			};
			class Holder
			{
				source="user";
				animPeriod=1e-006;
				initPhase=1;
			};
			class Gun_HRot
			{
				source="user";
				animPeriod=1e-006;
				initPhase=0;
			};
			class Gun_VRot
			{
				source="user";
				animPeriod=1e-006;
				initPhase=0;
			};
			class Minigun
			{
				source="revolving";
				weapon="DEGA_LMG_Minigun_Transport";
			};
			class Muzzle_flash
			{
				source="ammorandom";
				weapon="DEGA_LMG_Minigun_Transport";
			};
			class Minigun2
			{
				source="revolving";
				weapon="DEGA_LMG_Minigun_Transport";
			};
			class Muzzle_flash2
			{
				source="ammorandom";
				weapon="DEGA_LMG_Minigun_Transport";
			};
		};
		class UserActions
		{
			class DoorL1_Open
			{
				userActionID = 50;
				displayName = "Open Left Cargo Door";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				radius = 2.5;
				radiusView = 0.2;
				showIn3D = 17;
				priority = 0.5;
				position = "door_L";
				available = 0;
				showWindow = 1;
				onlyForPlayer = 1;
				shortcut = "";
				condition = "this doorPhase 'Door_L' < 0.5 AND Alive(this) && {(player in [this turretUnit [3]])}";
				statement = "this animateDoor ['door_L', 1]";
			};
			class DoorR1_Open: DoorL1_Open
			{
				userActionID = 51;
				displayName = "Open Right Cargo Door";
				position = "door_R";
				condition = "this doorPhase 'Door_R' < 0.5 AND Alive(this) && {(player in [this turretUnit [4]])}";
				statement = "this animateDoor ['door_R', 1]";
			};
			class DoorL1_Close: DoorL1_Open
			{
				userActionID = 53;
				displayName = "Close Left Cargo Door";
				condition = "this doorPhase 'Door_L' > 0.5 AND Alive(this) && {(player in [this turretUnit [3]])}";
				statement = "this animateDoor ['door_L', 0]";
			};
			class DoorR1_Close: DoorL1_Close
			{
				userActionID = 54;
				displayName = "Close Right Cargo Door";
				position = "door_R";
				condition = "this doorPhase 'Door_R' > 0.5 AND Alive(this) && {(player in [this turretUnit [4]])}"; 
				statement = "this animateDoor ['door_R', 0]";
			};
		};		
		class Turrets: Turrets
		{
			class CopilotTurret: CopilotTurret
			{
				canLock = 2;	
				proxyType = CPGunner;		
				inGunnerMayFire = true;				
				CanEject=0;
				gunnerAction="pilot_Heli_Transport_01";
				gunnerInAction="pilot_Heli_Transport_01";
				memoryPointsGetInGunner="pos copilot";
				memoryPointsGetInGunnerDir="pos copilot dir";
				gunnerGetInAction="GetInHeli_Transport_01Cargo";
				gunnerGetOutAction="GetOutLow";
				preciseGetInOut=0;
				GunnerDoor="";
				gunnerLeftHandAnimName="lever_copilot";
				gunnerRightHandAnimName="stick_copilot";
				gunnerLeftLegAnimName="PedalL";
				gunnerRightLegAnimName="PedalR";
				proxyIndex=3;
				LODTurnedIn=1100;
				LODTurnedOut=1100;
				gunnerCompartments="Compartment3";
				commanding=-3;
				class ViewGunner: ViewPilot
				{
				};
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftPilot
					{
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightPilot
					{
					};
				};
				class Hitpoints
				{
				};
				selectionFireAnim="";	
				
			};
			class CargoTurret_LeftWindow: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction                = "dega_leftgunner_heli_transport_01"; /// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01 
				gunnerInAction              = "dega_leftgunner_heli_transport_01";	/// generic animation for sitting inside with rifle ready gunner_Heli_Transport_01		
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos gunner";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos gunner dir";	/// direction of get in action
				gunnerName 					= "Passenger (Left Window Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 1;					/// what cargo proxy is used according to index in the model
				minElev 				    = -50;
				maxElev 				    = 15;
				initElev 				    = -15;
				minTurn 				    = 15;
				maxTurn 				    = 160;
				initTurn 				    = 0;
				isPersonTurret 				= 0;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "";				/// doesn't work unless the said animation source is 1
				gunnerDoor="";
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 0;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1000;
				LODTurnedOut = 1000;
				proxyType = CPGunner;
				selectionFireAnim="zasleh";
				soundAttenuationTurret="HeliAttenuationGunner";
				showAsCargo = 1;
				hideWeaponsGunner = 1;
			};
			class CargoTurret_RightWindow: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction                = "dega_rightgunner_heli_transport_01"; /// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01
				gunnerInAction              = "dega_rightgunner_Heli_Transport_01";	/// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos gunner2";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos gunner2 dir";	/// direction of get in action
				gunnerName 					= "Passenger (Right Window Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 2;					/// what cargo proxy is used according to index in the model
				minElev 				    = -50;
				maxElev 				    = 15;
				initElev 				    = -15;				
				minTurn 				    = -160;
				maxTurn 				    = -15;
				initTurn 				    = 0;
				isPersonTurret 				= 0;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "";				/// doesn't work unless the said animation source is 1
				gunnerDoor="";
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 0;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1000;
				LODTurnedOut = 1000;
				proxyType = CPGunner;
				selectionFireAnim="zasleh_1";
				soundAttenuationTurret="HeliAttenuationGunner";
				showAsCargo = 1;
				hideWeaponsGunner = 1;
			};
			class CargoTurret_LeftDoor: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerGetInAction = "GetInLOW";
				gunnerGetOutAction = "GetOutLOW";
				CanEject = 1;
				playerPosition = 4;
				class dynamicViewLimits
				{
					CargoTurret_RightDoor[] = {-65,95};
				};				
				gunnerAction                = "dega_passenger_inside_7_left"; /// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01
				gunnerInAction              = "dega_rightgunner_Heli_Transport_01";	/// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir";	/// direction of get in action
				gunnerName 					= "Passenger (Left Door Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 4;					/// what cargo proxy is used according to index in the model
				minElev 				    = -50;
				maxElev 				    = 35;
				initElev 				    = -15;				
				minTurn 				    = -150;
				maxTurn 				    = -20;
				initTurn 				    = 0;
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "door_L";				/// doesn't work unless the said animation source is 1
				gunnerDoor="";
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1200;
				LODTurnedOut = 1200;
				proxyType = CPCargo;
				soundAttenuationTurret="";
				showAsCargo = 1;
				hideWeaponsGunner = 0;
			};
			class CargoTurret_LeftFloorDoor: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerGetInAction = "GetInLOW";
				gunnerGetOutAction = "GetOutLOW";
				CanEject = 1;
				playerPosition = 4;
				class dynamicViewLimits
				{
					CargoTurret_RightDoor[] = {-65,95};
				};				
				gunnerAction                = "dega_passenger_inside_7_leftfloor"; /// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01
				gunnerInAction              = "dega_rightgunner_Heli_Transport_01";	/// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir";	/// direction of get in action
				gunnerName 					= "Passenger (Left Floor Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 3;					/// what cargo proxy is used according to index in the model
				minElev 				    = -50;
				maxElev 				    = 35;
				initElev 				    = -15;				
				minTurn 				    = 10;
				maxTurn 				    = 100;
				initTurn 				    = 0;
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "door_L";				/// doesn't work unless the said animation source is 1
				gunnerDoor="";
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1200;
				LODTurnedOut = 1200;
				proxyType = CPCargo;
				soundAttenuationTurret="";
				showAsCargo = 1;
				hideWeaponsGunner = 0;
			};				
			class CargoTurret_RightDoor: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerGetInAction = "GetInLOW";
				gunnerGetOutAction = "GetOutLOW";
				CanEject = 1;
				playerPosition = 4;
				class dynamicViewLimits
				{
					CargoTurret_LeftDoor[] = {-65,95};
				};				
				gunnerAction                = "passenger_inside_7"; /// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01
				gunnerInAction              = "dega_rightgunner_Heli_Transport_01";	/// generic animation for sitting inside with rifle ready  gunner_Heli_Transport_01
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir";	/// direction of get in action
				gunnerName 					= "Passenger (Right Door Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 2;					/// what cargo proxy is used according to index in the model
				minElev 				    = -50;
				maxElev 				    = 15;
				initElev 				    = -15;				
				minTurn 				    = 25;
				maxTurn 				    = 80;
				initTurn 				    = 0;
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "door_R";				/// doesn't work unless the said animation source is 1
				gunnerDoor="";
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1200;
				LODTurnedOut = 1200;
				proxyType = CPCargo;
				soundAttenuationTurret="";
				showAsCargo = 1;
				hideWeaponsGunner = 0;
			};			
		};
	};
};
class cfgMagazines
{
	class 2000Rnd_65x39_Belt;
	class DEGA_4000Rnd_65x39_Belt_Tracer_Red: 2000Rnd_65x39_Belt
	{
		author="Deltagamer";
		count=4000;
		tracersEvery=1;
		ammo="B_65x39_Minigun_Caseless_Red_splash";
		displayName="$STR_A3_CfgMagazines_2000Rnd_65x39_Belt_Tracer_Red0";
		descriptionShort="$STR_A3_CfgMagazines_2000Rnd_65x39_Belt_Tracer_Red1";
		displaynameshort="$STR_A3_tracer_dns";
		weight=30;
	};	
};
class CfgWeapons
{
	class LMG_Minigun;
	class DEGA_LMG_Minigun_Transport: LMG_Minigun
	{
		magazines[]=
		{
			"DEGA_4000Rnd_65x39_Belt_Tracer_Red"
		};		
		class GunParticles
		{
			class effect1
			{
				positionName="machinegun_eject_pos";
				directionName="machinegun_eject_dir";
				effectName="MachineGunCartridgeShort1";
			};
			class effect2
			{
				positionName="machinegun_end";
				directionName="machinegun_beg";
				effectName="MachineGun1";
			};
			class effect3
			{
				positionName="machinegun2_eject_pos";
				directionName="machinegun2_eject_dir";
				effectName="MachineGunCartridgeShort1";
			};
			class effect4
			{
				positionName="machinegun2_end";
				directionName="machinegun2_beg";
				effectName="MachineGun1";
			};			
		};
	};
	class RocketPods;
	class DEGA_missiles_DAGR: RocketPods
	{
		displayName="$STR_A3_missiles_DAGR0";
		magazines[]=
		{
			"24Rnd_PG_missiles",
			"12Rnd_PG_missiles",
			"PylonRack_12Rnd_PG_missiles"
		};
		modes[]=
		{
			"Far_AI",
			"Medium_AI",
			"Burst"
		};
		canLock=2;
		weaponLockDelay=3;
		weaponLockSystem=2;
		cmImmunity=0.30000001;
		lockingTargetSound[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			0.56234133,
			1
		};
		lockedTargetSound[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			0.56234133,
			2.5
		};
		cursor="EmptyCursor";
		cursorAim="missile";
		showAimCursorInternal=1;
		holdsterAnimValue=1;
		class Far_AI: RocketPods
		{
			displayName="$STR_A3_missiles_DAGR0";
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"A3\Sounds_F\weapons\Rockets\new_rocket_7",
					1.7782794,
					1.2,
					1600
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			autoFire=0;
			dispersion=0.015;
			showToPlayer=0;
			burst=1;
			burstRangeMax=1;
			aiRateOfFire=3;
			aiRateOfFireDispersion=3;
			aiRateOfFireDistance=1000;
			minRange=600;
			minRangeProbab=0.89999998;
			midRange=3000;
			midRangeProbab=0.89999998;
			maxRange=5000;
			maxRangeProbab=0.30000001;
		};
		class Medium_AI: Far_AI
		{
			showToPlayer=0;
			burst=1;
			burstRangeMax=2;
			aiRateOfFire=2;
			aiRateOfFireDispersion=2;
			aiRateOfFireDistance=400;
			minRange=300;
			minRangeProbab=0.2;
			midRange=600;
			midRangeProbab=0.89999998;
			maxRange=3000;
			maxRangeProbab=0.30000001;
		};
		class Burst: RocketPods
		{
			displayName="$STR_A3_missiles_DAGR0";
			burst=1;
			soundContinuous=0;
			autoFire=0;
			reloadTime=0.079999998;
			dispersion=0.015;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"A3\Sounds_F\weapons\Rockets\new_rocket_7",
					1.7782794,
					1.2,
					1600
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			textureType="semi";
		};
	};	
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		dega_rightgunner_Heli_Transport_01_KIA = "dega_rightgunner_Heli_Transport_01_KIA";
		dega_leftgunner_Heli_Transport_01_KIA = "dega_leftgunner_Heli_Transport_01_KIA";
		dega_rightgunner_heli_transport_01 = "dega_rightgunner_heli_transport_01";
		dega_leftgunner_heli_transport_01 = "dega_leftgunner_heli_transport_01";
		
		dega_passenger_inside_7_left="dega_passenger_inside_7_left_Idle";
		dega_passenger_inside_7_leftfloor="dega_passenger_inside_7_leftfloor_Idle";		
	};
	class Actions
	{
		class RifleStandActions;
		class FFV_BaseActions: RifleStandActions
		{
			AdjustF="";
			AdjustB="";
			AdjustL="";
			AdjustR="";
			AdjustLF="";
			AdjustLB="";
			AdjustRB="";
			AdjustRF="";
			agonyStart="";
			agonyStop="";
			medicStop="";
			medicStart="";
			medicStartUp="";
			medicStartRightSide="";
			GestureAgonyCargo="";
			grabCarry="";
			grabCarried="";
			grabDrag="";
			grabDragged="";
			carriedStill="";
			released="";
			releasedBad="";
			Stop="";
			StopRelaxed="";
			TurnL="";
			TurnR="";
			TurnLRelaxed="";
			TurnRRelaxed="";
			ReloadMagazine="";
			ReloadMGun="";
			ReloadRPG="ReloadRPG";
			ReloadMortar="";
			WalkF="";
			WalkLF="";
			WalkRF="";
			WalkL="";
			WalkR="";
			WalkLB="";
			WalkRB="";
			WalkB="";
			PlayerWalkF="";
			PlayerWalkLF="";
			PlayerWalkRF="";
			PlayerWalkL="";
			PlayerWalkR="";
			PlayerWalkLB="";
			PlayerWalkRB="";
			PlayerWalkB="";
			SlowF="";
			SlowLF="";
			SlowRF="";
			SlowL="";
			SlowR="";
			SlowLB="";
			SlowRB="";
			SlowB="";
			PlayerSlowF="";
			PlayerSlowLF="";
			PlayerSlowRF="";
			PlayerSlowL="";
			PlayerSlowR="";
			PlayerSlowLB="";
			PlayerSlowRB="";
			PlayerSlowB="";
			FastF="";
			FastLF="";
			FastRF="";
			FastL="";
			FastR="";
			FastLB="";
			FastRB="";
			FastB="";
			TactF="";
			TactLF="";
			TactRF="";
			TactL="";
			TactR="";
			TactLB="";
			TactRB="";
			TactB="";
			PlayerTactF="";
			PlayerTactLF="";
			PlayerTactRF="";
			PlayerTactL="";
			PlayerTactR="";
			PlayerTactLB="";
			PlayerTactRB="";
			PlayerTactB="";
			EvasiveLeft="";
			EvasiveRight="";
			startSwim="";
			surfaceSwim="";
			bottomSwim="";
			StopSwim="";
			startDive="";
			SurfaceDive="";
			BottomDive="";
			StopDive="";
			Down="";
			Up="";
			PlayerStand="";
			PlayerCrouch="";
			PlayerProne="";
			Lying="";
			Stand="";
			Combat="";
			Crouch="";
			CanNotMove="";
			Civil="";
			CivilLying="";
			FireNotPossible="";
			WeaponOn="";
			WeaponOff="";
			Default="";
			JumpOff="";
			StrokeFist="";
			StrokeGun="";
			SitDown="";
			Salute="";
			saluteOff="";
			GetOver="";
			Diary="";
			Surrender="";
			Gear="";
			BinocOn="";
			BinocOff="";
			PutDown="";
			PutDownEnd="";
			Medic="";
			MedicOther="";
			Treated="";
			LadderOnDown="";
			LadderOnUp="";
			LadderOff="";
			LadderOffTop="";
			LadderOffBottom="";
			PrimaryWeapon="";
			SecondaryWeapon="";
			Binoculars="";
			Obstructed="";
		};	
////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		class dega_passenger_inside_7_leftActions: FFV_BaseActions
		{
			upDegree="ManPosCombat";
			stop="dega_passenger_inside_7_left_Aim";
			stopRelaxed="dega_passenger_inside_7_left_Aim";
			default="dega_passenger_inside_7_left_Aim";
			Stand="dega_passenger_inside_7_left_Idle";
			HandGunOn="dega_passenger_inside_7_left_Aim_Pistol";
			PrimaryWeapon="dega_passenger_inside_7_left_Aim";
			Binoculars="dega_passenger_inside_7_left_Aim_Binoc";
			die="dega_passenger_inside_7_left_Die";
			Unconscious="dega_passenger_inside_7_left_Die";
			civil="dega_passenger_inside_7_left_Idle_Unarmed";
			Obstructed="dega_passenger_inside_7_left_Obstructed";
		};
		class dega_passenger_inside_7_leftIdleUnarmedActions: FFV_BaseActions
		{
			upDegree="ManPosNoWeapon";
			stop="dega_passenger_inside_7_left_Idle_Unarmed";
			stopRelaxed="dega_passenger_inside_7_left_Idle_Unarmed";
			default="dega_passenger_inside_7_left_Idle_Unarmed";
			Stand="dega_passenger_inside_7_left_Idle_Unarmed";
			HandGunOn="dega_passenger_inside_7_left_Aim_Pistol";
			PrimaryWeapon="dega_passenger_inside_7_left_Aim";
			Binoculars="dega_passenger_inside_7_left_Aim_Unarmed_Binoc";
			die="dega_passenger_inside_7_left_Die_Pistol";
			Unconscious="dega_passenger_inside_7_left_Die_Pistol";
			civil="dega_passenger_inside_7_left_Idle_Unarmed";
			throwGrenade[]=
			{
				"GestureThrowGrenadeUna",
				"Gesture"
			};
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftDeadActions: FFV_BaseActions
		{
			stop="dega_passenger_inside_7_left_Die";
			default="dega_passenger_inside_7_left_Die";
			die="dega_passenger_inside_7_left_Die";
			Unconscious="dega_passenger_inside_7_left_Die";
		};
		class dega_passenger_inside_7_leftDeadPistolActions: FFV_BaseActions
		{
			stop="dega_passenger_inside_7_left_Die_Pistol";
			default="dega_passenger_inside_7_left_Die_Pistol";
			die="dega_passenger_inside_7_left_Die_Pistol";
			Unconscious="dega_passenger_inside_7_left_Die_Pistol";
		};
		class dega_passenger_inside_7_leftPistolActions: dega_passenger_inside_7_leftActions
		{
			upDegree="ManPosHandGunStand";
			stop="dega_passenger_inside_7_left_Aim_Pistol";
			stopRelaxed="dega_passenger_inside_7_left_Aim_Pistol";
			default="dega_passenger_inside_7_left_Aim_Pistol";
			Binoculars="dega_passenger_inside_7_left_Aim_Pistol_Binoc";
			throwGrenade[]=
			{
				"GestureThrowGrenadePistol",
				"Gesture"
			};
			Stand="dega_passenger_inside_7_left_Idle_Pistol";
			die="dega_passenger_inside_7_left_Die_Pistol";
			Unconscious="dega_passenger_inside_7_left_Die_Pistol";
			Obstructed="dega_passenger_inside_7_left_Obstructed_Pistol";
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftBinocActions: dega_passenger_inside_7_leftActions
		{
			binocOn="";
			upDegree="ManPosBinocStand";
			stop="dega_passenger_inside_7_left_Aim_Binoc";
			stopRelaxed="dega_passenger_inside_7_left_Aim_Binoc";
			default="dega_passenger_inside_7_left_Aim_Binoc";
		};
		class dega_passenger_inside_7_leftBinocPistolActions: dega_passenger_inside_7_leftBinocActions
		{
			stop="dega_passenger_inside_7_left_Aim_Pistol_Binoc";
			stopRelaxed="dega_passenger_inside_7_left_Aim_Pistol_Binoc";
			default="dega_passenger_inside_7_left_Aim_Pistol_Binoc";
			die="dega_passenger_inside_7_left_Die_Pistol";
			Unconscious="dega_passenger_inside_7_left_Die_Pistol";
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftBinocUnarmedActions: dega_passenger_inside_7_leftBinocActions
		{
			stop="dega_passenger_inside_7_left_Aim_Unarmed_Binoc";
			stopRelaxed="dega_passenger_inside_7_left_Aim_Unarmed_Binoc";
			default="dega_passenger_inside_7_left_Aim_Unarmed_Binoc";
			die="dega_passenger_inside_7_left_Die_Pistol";
			Unconscious="dega_passenger_inside_7_left_Die_Pistol";
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftIdleActions: dega_passenger_inside_7_leftActions
		{
			upDegree="ManPosStand";
			stop="dega_passenger_inside_7_left_Idle";
			stopRelaxed="dega_passenger_inside_7_left_Idle";
			default="dega_passenger_inside_7_left_Idle";
			Combat="dega_passenger_inside_7_left_Aim";
			fireNotPossible="dega_passenger_inside_7_left_Aim";
			PlayerStand="dega_passenger_inside_7_left_Aim";
		};
		class dega_passenger_inside_7_leftIdlePistolActions: dega_passenger_inside_7_leftActions
		{
			Stand="dega_passenger_inside_7_left_Idle_Pistol";
			upDegree="ManPosHandGunStand";
			stop="dega_passenger_inside_7_left_Idle_Pistol";
			stopRelaxed="dega_passenger_inside_7_left_Idle_Pistol";
			default="dega_passenger_inside_7_left_Idle_Pistol";
			Combat="dega_passenger_inside_7_left_Aim_Pistol";
			fireNotPossible="dega_passenger_inside_7_left_Aim_Pistol";
			PlayerStand="dega_passenger_inside_7_left_Aim_Pistol";
			die="dega_passenger_inside_7_left_Die_Pistol";
			Unconscious="dega_passenger_inside_7_left_Die_Pistol";
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftObstructedActions: dega_passenger_inside_7_leftActions
		{
			stop="dega_passenger_inside_7_left_Obstructed";
			stopRelaxed="dega_passenger_inside_7_left_Obstructed";
			default="dega_passenger_inside_7_left_Obstructed";
			Combat="dega_passenger_inside_7_left_Aim";
			fireNotPossible="dega_passenger_inside_7_left_Obstructed";
			PlayerStand="dega_passenger_inside_7_left_Obstructed";
		};
		class dega_passenger_inside_7_leftObstructedPistolActions: dega_passenger_inside_7_leftPistolActions
		{
			Stand="dega_passenger_inside_7_left_Obstructed_Pistol";
			stop="dega_passenger_inside_7_left_Obstructed_Pistol";
			stopRelaxed="dega_passenger_inside_7_left_Obstructed_Pistol";
			default="dega_passenger_inside_7_left_Obstructed_Pistol";
			Combat="dega_passenger_inside_7_left_Aim_Pistol";
			fireNotPossible="dega_passenger_inside_7_left_Obstructed_Pistol";
			PlayerStand="dega_passenger_inside_7_left_Obstructed_Pistol";
		};
////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		class dega_passenger_inside_7_leftfloorActions: FFV_BaseActions
		{
			upDegree="ManPosCombat";
			stop="dega_passenger_inside_7_leftfloor_Aim";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Aim";
			default="dega_passenger_inside_7_leftfloor_Aim";
			Stand="dega_passenger_inside_7_leftfloor_Idle";
			HandGunOn="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			PrimaryWeapon="dega_passenger_inside_7_leftfloor_Aim";
			Binoculars="dega_passenger_inside_7_leftfloor_Aim_Binoc";
			die="dega_passenger_inside_7_leftfloor_Die";
			Unconscious="dega_passenger_inside_7_leftfloor_Die";
			civil="dega_passenger_inside_7_leftfloor_Idle_Unarmed";
			Obstructed="dega_passenger_inside_7_leftfloor_Obstructed";
		};
		class dega_passenger_inside_7_leftfloorIdleUnarmedActions: FFV_BaseActions
		{
			upDegree="ManPosNoWeapon";
			stop="dega_passenger_inside_7_leftfloor_Idle_Unarmed";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Idle_Unarmed";
			default="dega_passenger_inside_7_leftfloor_Idle_Unarmed";
			Stand="dega_passenger_inside_7_leftfloor_Idle_Unarmed";
			HandGunOn="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			PrimaryWeapon="dega_passenger_inside_7_leftfloor_Aim";
			Binoculars="dega_passenger_inside_7_leftfloor_Aim_Unarmed_Binoc";
			die="dega_passenger_inside_7_leftfloor_Die_Pistol";
			Unconscious="dega_passenger_inside_7_leftfloor_Die_Pistol";
			civil="dega_passenger_inside_7_leftfloor_Idle_Unarmed";
			throwGrenade[]=
			{
				"GestureThrowGrenadeUna",
				"Gesture"
			};
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftfloorDeadActions: FFV_BaseActions
		{
			stop="dega_passenger_inside_7_leftfloor_Die";
			default="dega_passenger_inside_7_leftfloor_Die";
			die="dega_passenger_inside_7_leftfloor_Die";
			Unconscious="dega_passenger_inside_7_leftfloor_Die";
		};
		class dega_passenger_inside_7_leftfloorDeadPistolActions: FFV_BaseActions
		{
			stop="dega_passenger_inside_7_leftfloor_Die_Pistol";
			default="dega_passenger_inside_7_leftfloor_Die_Pistol";
			die="dega_passenger_inside_7_leftfloor_Die_Pistol";
			Unconscious="dega_passenger_inside_7_leftfloor_Die_Pistol";
		};
		class dega_passenger_inside_7_leftfloorPistolActions: dega_passenger_inside_7_leftfloorActions
		{
			upDegree="ManPosHandGunStand";
			stop="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			default="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			Binoculars="dega_passenger_inside_7_leftfloor_Aim_Pistol_Binoc";
			throwGrenade[]=
			{
				"GestureThrowGrenadePistol",
				"Gesture"
			};
			Stand="dega_passenger_inside_7_leftfloor_Idle_Pistol";
			die="dega_passenger_inside_7_leftfloor_Die_Pistol";
			Unconscious="dega_passenger_inside_7_leftfloor_Die_Pistol";
			Obstructed="dega_passenger_inside_7_leftfloor_Obstructed_Pistol";
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftfloorBinocActions: dega_passenger_inside_7_leftfloorActions
		{
			binocOn="";
			upDegree="ManPosBinocStand";
			stop="dega_passenger_inside_7_leftfloor_Aim_Binoc";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Aim_Binoc";
			default="dega_passenger_inside_7_leftfloor_Aim_Binoc";
		};
		class dega_passenger_inside_7_leftfloorBinocPistolActions: dega_passenger_inside_7_leftfloorBinocActions
		{
			stop="dega_passenger_inside_7_leftfloor_Aim_Pistol_Binoc";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Aim_Pistol_Binoc";
			default="dega_passenger_inside_7_leftfloor_Aim_Pistol_Binoc";
			die="dega_passenger_inside_7_leftfloor_Die_Pistol";
			Unconscious="dega_passenger_inside_7_leftfloor_Die_Pistol";
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftfloorBinocUnarmedActions: dega_passenger_inside_7_leftfloorBinocActions
		{
			stop="dega_passenger_inside_7_leftfloor_Aim_Unarmed_Binoc";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Aim_Unarmed_Binoc";
			default="dega_passenger_inside_7_leftfloor_Aim_Unarmed_Binoc";
			die="dega_passenger_inside_7_leftfloor_Die_Pistol";
			Unconscious="dega_passenger_inside_7_leftfloor_Die_Pistol";
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftfloorIdleActions: dega_passenger_inside_7_leftfloorActions
		{
			upDegree="ManPosStand";
			stop="dega_passenger_inside_7_leftfloor_Idle";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Idle";
			default="dega_passenger_inside_7_leftfloor_Idle";
			Combat="dega_passenger_inside_7_leftfloor_Aim";
			fireNotPossible="dega_passenger_inside_7_leftfloor_Aim";
			PlayerStand="dega_passenger_inside_7_leftfloor_Aim";
		};
		class dega_passenger_inside_7_leftfloorIdlePistolActions: dega_passenger_inside_7_leftfloorActions
		{
			Stand="dega_passenger_inside_7_leftfloor_Idle_Pistol";
			upDegree="ManPosHandGunStand";
			stop="dega_passenger_inside_7_leftfloor_Idle_Pistol";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Idle_Pistol";
			default="dega_passenger_inside_7_leftfloor_Idle_Pistol";
			Combat="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			fireNotPossible="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			PlayerStand="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			die="dega_passenger_inside_7_leftfloor_Die_Pistol";
			Unconscious="dega_passenger_inside_7_leftfloor_Die_Pistol";
			GetOutLow="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutLow";
			GetOutMedium="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutMedium";
			GetOutHigh="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
			GetOutHighZamak="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighZamak";
			GetOutHighHemtt="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighHemtt";
			GetOutSDV="AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
		};
		class dega_passenger_inside_7_leftfloorObstructedActions: dega_passenger_inside_7_leftfloorActions
		{
			stop="dega_passenger_inside_7_leftfloor_Obstructed";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Obstructed";
			default="dega_passenger_inside_7_leftfloor_Obstructed";
			Combat="dega_passenger_inside_7_leftfloor_Aim";
			fireNotPossible="dega_passenger_inside_7_leftfloor_Obstructed";
			PlayerStand="dega_passenger_inside_7_leftfloor_Obstructed";
		};
		class dega_passenger_inside_7_leftfloorObstructedPistolActions: dega_passenger_inside_7_leftfloorPistolActions
		{
			Stand="dega_passenger_inside_7_leftfloor_Obstructed_Pistol";
			stop="dega_passenger_inside_7_leftfloor_Obstructed_Pistol";
			stopRelaxed="dega_passenger_inside_7_leftfloor_Obstructed_Pistol";
			default="dega_passenger_inside_7_leftfloor_Obstructed_Pistol";
			Combat="dega_passenger_inside_7_leftfloor_Aim_Pistol";
			fireNotPossible="dega_passenger_inside_7_leftfloor_Obstructed_Pistol";
			PlayerStand="dega_passenger_inside_7_leftfloor_Obstructed_Pistol";
		};		
    };		
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class cargo_base;
		class cargo_base_idle;
		class cargo_basepistol;
		class cargo_base_idle_pistol;
		class cargo_basebinoc;
		class AmovPercMstpSrasWrflDnon;
		class AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWpstDnon;
		class AmovPercMstpSrasWrflDnon_AmovPercMstpSrasWpstDnon_end;
		class AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon;
		class AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon_end;
		class AmovPercMstpSrasWpstDnon;
		class AmovPercMstpSrasWpstDnon_AmovPercMstpSrasWrflDnon;
		class AmovPercMstpSrasWpstDnon_AmovPercMstpSrasWrflDnon_end;
		class AmovPpneMstpSrasWpstDnon_AmovPpneMstpSrasWrflDnon;
		class AmovPpneMstpSrasWpstDnon_AmovPpneMstpSrasWrflDnon_end;
		class AmovPercMstpSoptWbinDnon;
		class AmovPercMstpSrasWrflDnon_AwopPercMstpSoptWbinDnon;
		class AmovPercMstpSrasWrflDnon_AwopPercMstpSoptWbinDnon_end;
		class AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWrflDnon;
		class AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWrflDnon_end;
		class AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon;
		class AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon_end;
		class AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon;
		class AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon_end;
		class dega_rightgunner_Heli_Transport_01_KIA: DefaultDie
		{
			actions="DeadActions";
			file="\dega_vehicles_MH80E\data\Anim\dega_rightgunner_Heli_Transport_01_KIA.rtm";
			speed=1;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"Unconscious",
				0.1
			};
		};	
		class dega_leftgunner_Heli_Transport_01_KIA: DefaultDie
		{
			actions="DeadActions";
			file="\dega_vehicles_MH80E\data\Anim\dega_leftgunner_Heli_Transport_01_KIA.rtm";
			speed=1;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"Unconscious",
				0.1
			};
		};			
		class dega_rightgunner_heli_transport_01: Crew
		{
			file="\dega_vehicles_MH80E\data\Anim\dega_rightgunner_heli_transport_01.rtm";
			speed=-30;
			interpolateTo[]=
			{
				"dega_rightgunner_Heli_Transport_01_KIA",
				1
			};
		};
		class dega_leftgunner_Heli_Transport_01: Crew
		{
			file="\dega_vehicles_MH80E\data\Anim\dega_leftgunner_heli_transport_01.rtm";
			speed=-30;
			interpolateTo[]=
			{
				"dega_leftgunner_Heli_Transport_01_KIA",
				1
			};
		};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		class dega_passenger_inside_7_left_Aim: cargo_base
		{
			actions="dega_passenger_inside_7_leftActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim.rtm";
			speed=100000;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_ToBinoc",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Idle",
				0.1,
				"dega_passenger_inside_7_left_toObstructed",
				0.1,
				"dega_passenger_inside_7_left_Aim_ToPistol",
				0.1,
				"dega_passenger_inside_7_left_Idle_Unarmed",
				0.2,
				"dega_passenger_inside_7_left_Die",
				0.1
			};
			variantsAI[]=
			{
				"dega_passenger_inside_7_left_Aim_Idling",
				1
			};
			variantsPlayer[]={};
		};
		class dega_passenger_inside_7_left_Obstructed: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftObstructedActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim_obstructed.rtm";
			speed=1e+010;
			weaponLowered=0;
			leftHandIKCurve[]={1};
			weaponObstructed=1;
			interpolationRestart=1;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_fromObstructed",
				0.1,
				"dega_passenger_inside_7_left_Die",
				0.1
			};
		};
		class dega_passenger_inside_7_left_fromObstructed: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim_fromobstructed.rtm";
			speed=-0.15000001;
			looped=0;
			weaponLowered=0;
			leftHandIKCurve[]={1};
			interpolationRestart=1;
			reverse="dega_passenger_inside_7_left_toObstructed";
			minplaytime=0.94999999;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim",
				0.1
			};
		};
		class dega_passenger_inside_7_left_toObstructed: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftObstructedActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim_toobstructed.rtm";
			speed=-0.15000001;
			weaponLowered=0;
			weaponObstructed=1;
			looped=0;
			leftHandIKCurve[]={1};
			interpolationRestart=1;
			reverse="dega_passenger_inside_7_left_fromObstructed";
			minplaytime=0.94999999;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Obstructed",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Obstructed",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Aim_Idling: dega_passenger_inside_7_left_Aim
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim1.rtm";
			speed=-8;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Idle: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftIdleActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7idle.rtm";
			speed=100000;
			aiming="aimingDefault";
			aimingBody="aimingNo";
			leftHandIKCurve[]={1};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim",
				0.1,
				"dega_passenger_inside_7_left_Aim_ToPistol",
				0.1,
				"dega_passenger_inside_7_left_Idle_Unarmed",
				0.2,
				"dega_passenger_inside_7_left_Die",
				0.1
			};
			variantsAI[]=
			{
				"dega_passenger_inside_7_left_Idle_Idling",
				1
			};
			variantsPlayer[]=
			{
				"dega_passenger_inside_7_left_Idle_Idling",
				1
			};
		};
		class dega_passenger_inside_7_left_Idle_Idling: dega_passenger_inside_7_left_Idle
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7idle1.rtm";
			speed=-10;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Idle",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Aim_Pistol: cargo_basepistol
		{
			actions="dega_passenger_inside_7_leftPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol.rtm";
			aiming="aimingRifleSlingDefault";
			aimingBody="aimingUpRifleSlingDefault";
			speed=100000;
			variantsAI[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol_Idling",
				1
			};
			variantsPlayer[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol_Idling",
				1
			};
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol_ToBinoc",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim_FromPistol",
				0.1,
				"dega_passenger_inside_7_left_Idle_Pistol",
				0.2,
				"dega_passenger_inside_7_left_toObstructed_Pistol",
				0.2,
				"dega_passenger_inside_7_left_Idle_Unarmed",
				0.2,
				"dega_passenger_inside_7_left_Die_Pistol",
				0.5
			};
		};
		class dega_passenger_inside_7_left_Aim_Pistol_Idling: dega_passenger_inside_7_left_Aim_Pistol
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol1.rtm";
			speed=-8;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Idle_Pistol: cargo_base_idle_pistol
		{
			actions="dega_passenger_inside_7_leftIdlePistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7idlepistol.rtm";
			speed=100000;
			aiming="aimingRifleSlingDefault";
			aimingBody="aimingUpRifleSlingDefault";
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol",
				0.1,
				"dega_passenger_inside_7_left_Aim_FromPistol",
				0.1,
				"dega_passenger_inside_7_left_Idle_Unarmed",
				0.1,
				"dega_passenger_inside_7_left_Die_Pistol",
				0.1
			};
			variantsAI[]=
			{
				"dega_passenger_inside_7_left_Idle_Pistol_Idling",
				1
			};
			variantsPlayer[]=
			{
				"dega_passenger_inside_7_left_Idle_Pistol_Idling",
				1
			};
		};
		class dega_passenger_inside_7_left_Idle_Pistol_Idling: dega_passenger_inside_7_left_Idle
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7idlepistol1.rtm";
			speed=-10;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Idle_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Obstructed_Pistol: cargo_base_idle_pistol
		{
			actions="dega_passenger_inside_7_leftObstructedPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol_obstructed.rtm";
			speed=1e+010;
			weaponLowered=0;
			weaponObstructed=1;
			interpolationRestart=1;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_fromObstructed_Pistol",
				0.1,
				"dega_passenger_inside_7_left_Die",
				0.1
			};
		};
		class dega_passenger_inside_7_left_fromObstructed_Pistol: cargo_base_idle_pistol
		{
			actions="dega_passenger_inside_7_leftPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol_fromobstructed.rtm";
			speed=-0.15000001;
			weaponLowered=0;
			interpolationRestart=1;
			looped=0;
			reverse="dega_passenger_inside_7_left_toObstructed_Pistol";
			minplaytime=0.94999999;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_left_toObstructed_Pistol: cargo_base_idle_pistol
		{
			actions="dega_passenger_inside_7_leftObstructedPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol_toobstructed.rtm";
			speed=-0.15000001;
			weaponLowered=0;
			interpolationRestart=1;
			looped=0;
			weaponObstructed=1;
			reverse="dega_passenger_inside_7_left_fromObstructed_Pistol";
			minplaytime=0.94999999;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Obstructed_Pistol",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Obstructed_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Aim_ToPistol: AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon
		{
			actions="dega_passenger_inside_7_leftPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimtopistol.rtm";
			speed=2;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_ToPistol_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_ToPistol_End: AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon_end
		{
			actions="dega_passenger_inside_7_leftPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimtopistol_end.rtm";
			speed=1.875;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_FromPistol: AmovPpneMstpSrasWpstDnon_AmovPpneMstpSrasWrflDnon
		{
			actions="dega_passenger_inside_7_leftPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimFrompistol.rtm";
			speed=2.3076921;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_FromPistol_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_FromPistol_End: AmovPpneMstpSrasWpstDnon_AmovPpneMstpSrasWrflDnon_end
		{
			actions="dega_passenger_inside_7_leftActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimfrompistol_end.rtm";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			speed=2;
			leftHandIKCurve[]={0,0,0.5,1};
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_Binoc: cargo_basebinoc
		{
			actions="dega_passenger_inside_7_leftBinocActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim_Binoc.rtm";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			speed=-8;
			rightHandIKCurve[]={0};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim_FromBinoc",
				0.1,
				"dega_passenger_inside_7_left_Die",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Aim_Pistol_Binoc: cargo_basebinoc
		{
			actions="dega_passenger_inside_7_leftBinocPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol_Binoc.rtm";
			aiming="aimingRifleSlingDefault";
			aimingBody="aimingUpRifleSlingDefault";
			showHandGun=1;
			speed=-8;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol_FromBinoc",
				0.1,
				"dega_passenger_inside_7_left_Die_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Aim_ToBinoc: AmovPercMstpSrasWrflDnon_AwopPercMstpSoptWbinDnon
		{
			actions="dega_passenger_inside_7_leftBinocActions";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim_ToBinoc.rtm";
			speed=1.5789469;
			leftHandIKCurve[]={0,1,0.15000001,0};
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_ToBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_ToBinoc_End: AmovPercMstpSrasWrflDnon_AwopPercMstpSoptWbinDnon_end
		{
			actions="dega_passenger_inside_7_leftBinocActions";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim_ToBinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Binoc",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_FromBinoc: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWrflDnon
		{
			actions="dega_passenger_inside_7_leftBinocActions";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim_frombinoc.rtm";
			speed=1.5789469;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_FromBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_FromBinoc_End: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWrflDnon_end
		{
			actions="dega_passenger_inside_7_leftActions";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aim_frombinoc_end.rtm";
			speed=1.764706;
			leftHandIKCurve[]={0,0,0.5,1};
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_Pistol_ToBinoc: AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon
		{
			actions="dega_passenger_inside_7_leftBinocActions";
			showHandGun=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol_ToBinoc.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol_ToBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_Pistol_ToBinoc_End: AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon_end
		{
			actions="dega_passenger_inside_7_leftBinocActions";
			showHandGun=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol_ToBinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol_Binoc",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_Pistol_FromBinoc: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon
		{
			actions="dega_passenger_inside_7_leftBinocActions";
			showHandGun=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol_frombinoc.rtm";
			speed=1.5789469;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol_FromBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_Pistol_FromBinoc_End: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon_end
		{
			actions="dega_passenger_inside_7_leftActions";
			showHandGun=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimpistol_frombinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Pistol",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Idle_Unarmed: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftIdleUnarmedActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7idleunarmed.rtm";
			speed=100000;
			aiming="aimingNo";
			aimingBody="aimingNo";
			weaponIK=0;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim_FromPistol_End",
				0.1,
				"dega_passenger_inside_7_left_Aim_ToPistol_End",
				0.1,
				"dega_passenger_inside_7_left_Aim_Unarmed_ToBinoc",
				0.1,
				"dega_passenger_inside_7_left_Die_Pistol",
				0.1
			};
			variantsAI[]=
			{
				"dega_passenger_inside_7_left_Idle_Unarmed_Idling",
				1
			};
			variantsPlayer[]=
			{
				"dega_passenger_inside_7_left_Idle_Unarmed_Idling",
				1
			};
		};
		class dega_passenger_inside_7_left_Idle_Unarmed_Idling: dega_passenger_inside_7_left_Idle
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7idleunarmed1.rtm";
			speed=-10;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Idle_Unarmed",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Aim_Unarmed_Binoc: cargo_basebinoc
		{
			actions="dega_passenger_inside_7_leftBinocUnarmedActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimUnarmed_Binoc.rtm";
			aiming="aimingRifleSlingDefault";
			aimingBody="aimingUpRifleSlingDefault";
			showHandGun=0;
			speed=-8;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Unarmed_FromBinoc",
				0.1,
				"dega_passenger_inside_7_left_Die_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_left_Aim_Unarmed_ToBinoc: AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon
		{
			actions="dega_passenger_inside_7_leftBinocUnarmedActions";
			showHandGun=0;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimUnarmed_ToBinoc.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Unarmed_ToBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_Unarmed_ToBinoc_End: AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon_end
		{
			actions="dega_passenger_inside_7_leftBinocUnarmedActions";
			showHandGun=0;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimUnarmed_ToBinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Unarmed_Binoc",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_Unarmed_FromBinoc: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon
		{
			actions="dega_passenger_inside_7_leftBinocUnarmedActions";
			showHandGun=0;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimUnarmed_frombinoc.rtm";
			speed=1.5789469;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Aim_Unarmed_FromBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Aim_Unarmed_FromBinoc_End: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon_end
		{
			actions="dega_passenger_inside_7_leftIdleUnarmedActions";
			showHandGun=0;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7aimUnarmed_frombinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_left_Idle_Unarmed",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Die: DefaultDie
		{
			actions="dega_passenger_inside_7_leftDeadActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7die.rtm";
			speed=1;
			looped=0;
			terminal=1;
			ragdoll=1;
			ConnectTo[]=
			{
				"Unconscious",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_left_Die_Pistol: dega_passenger_inside_7_left_Die
		{
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_left\passenger_inside_7diepistol.rtm";
			actions="dega_passenger_inside_7_leftDeadPistolActions";
			showHandGun=1;
		};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		class dega_passenger_inside_7_leftfloor_Aim: cargo_base
		{
			actions="dega_passenger_inside_7_leftfloorActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim.rtm";
			speed=100000;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_ToBinoc",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle",
				0.1,
				"dega_passenger_inside_7_leftfloor_toObstructed",
				0.1,
				"dega_passenger_inside_7_leftfloor_Aim_ToPistol",
				0.1,
				"dega_passenger_inside_7_leftfloor_Idle_Unarmed",
				0.2,
				"dega_passenger_inside_7_leftfloor_Die",
				0.1
			};
			variantsAI[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Idling",
				1
			};
			variantsPlayer[]={};
		};
		class dega_passenger_inside_7_leftfloor_Obstructed: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftfloorObstructedActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim_obstructed.rtm";
			speed=1e+010;
			weaponLowered=0;
			leftHandIKCurve[]={1};
			weaponObstructed=1;
			interpolationRestart=1;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_fromObstructed",
				0.1,
				"dega_passenger_inside_7_leftfloor_Die",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_fromObstructed: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftfloorActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim_fromobstructed.rtm";
			speed=-0.15000001;
			looped=0;
			weaponLowered=0;
			leftHandIKCurve[]={1};
			interpolationRestart=1;
			reverse="dega_passenger_inside_7_leftfloor_toObstructed";
			minplaytime=0.94999999;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_toObstructed: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftfloorObstructedActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim_toobstructed.rtm";
			speed=-0.15000001;
			weaponLowered=0;
			weaponObstructed=1;
			looped=0;
			leftHandIKCurve[]={1};
			interpolationRestart=1;
			reverse="dega_passenger_inside_7_leftfloor_fromObstructed";
			minplaytime=0.94999999;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Obstructed",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Obstructed",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Idling: dega_passenger_inside_7_leftfloor_Aim
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim1.rtm";
			speed=-8;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Idle: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftfloorIdleActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7idle.rtm";
			speed=100000;
			aiming="aimingDefault";
			aimingBody="aimingNo";
			leftHandIKCurve[]={1};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim",
				0.1,
				"dega_passenger_inside_7_leftfloor_Aim_ToPistol",
				0.1,
				"dega_passenger_inside_7_leftfloor_Idle_Unarmed",
				0.2,
				"dega_passenger_inside_7_leftfloor_Die",
				0.1
			};
			variantsAI[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Idling",
				1
			};
			variantsPlayer[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Idling",
				1
			};
		};
		class dega_passenger_inside_7_leftfloor_Idle_Idling: dega_passenger_inside_7_leftfloor_Idle
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7idle1.rtm";
			speed=-10;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Pistol: cargo_basepistol
		{
			actions="dega_passenger_inside_7_leftfloorPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol.rtm";
			aiming="aimingRifleSlingDefault";
			aimingBody="aimingUpRifleSlingDefault";
			speed=100000;
			variantsAI[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol_Idling",
				1
			};
			variantsPlayer[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol_Idling",
				1
			};
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol_ToBinoc",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_FromPistol",
				0.1,
				"dega_passenger_inside_7_leftfloor_Idle_Pistol",
				0.2,
				"dega_passenger_inside_7_leftfloor_toObstructed_Pistol",
				0.2,
				"dega_passenger_inside_7_leftfloor_Idle_Unarmed",
				0.2,
				"dega_passenger_inside_7_leftfloor_Die_Pistol",
				0.5
			};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Pistol_Idling: dega_passenger_inside_7_leftfloor_Aim_Pistol
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol1.rtm";
			speed=-8;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Idle_Pistol: cargo_base_idle_pistol
		{
			actions="dega_passenger_inside_7_leftfloorIdlePistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7idlepistol.rtm";
			speed=100000;
			aiming="aimingRifleSlingDefault";
			aimingBody="aimingUpRifleSlingDefault";
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol",
				0.1,
				"dega_passenger_inside_7_leftfloor_Aim_FromPistol",
				0.1,
				"dega_passenger_inside_7_leftfloor_Idle_Unarmed",
				0.1,
				"dega_passenger_inside_7_leftfloor_Die_Pistol",
				0.1
			};
			variantsAI[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Pistol_Idling",
				1
			};
			variantsPlayer[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Pistol_Idling",
				1
			};
		};
		class dega_passenger_inside_7_leftfloor_Idle_Pistol_Idling: dega_passenger_inside_7_leftfloor_Idle
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7idlepistol1.rtm";
			speed=-10;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Obstructed_Pistol: cargo_base_idle_pistol
		{
			actions="dega_passenger_inside_7_leftfloorObstructedPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol_obstructed.rtm";
			speed=1e+010;
			weaponLowered=0;
			weaponObstructed=1;
			interpolationRestart=1;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_fromObstructed_Pistol",
				0.1,
				"dega_passenger_inside_7_leftfloor_Die",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_fromObstructed_Pistol: cargo_base_idle_pistol
		{
			actions="dega_passenger_inside_7_leftfloorPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol_fromobstructed.rtm";
			speed=-0.15000001;
			weaponLowered=0;
			interpolationRestart=1;
			looped=0;
			reverse="dega_passenger_inside_7_leftfloor_toObstructed_Pistol";
			minplaytime=0.94999999;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_toObstructed_Pistol: cargo_base_idle_pistol
		{
			actions="dega_passenger_inside_7_leftfloorObstructedPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol_toobstructed.rtm";
			speed=-0.15000001;
			weaponLowered=0;
			interpolationRestart=1;
			looped=0;
			weaponObstructed=1;
			reverse="dega_passenger_inside_7_leftfloor_fromObstructed_Pistol";
			minplaytime=0.94999999;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Obstructed_Pistol",
				0.1
			};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Obstructed_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Aim_ToPistol: AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon
		{
			actions="dega_passenger_inside_7_leftfloorPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimtopistol.rtm";
			speed=2;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_ToPistol_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_ToPistol_End: AmovPpneMstpSrasWrflDnon_AmovPpneMstpSrasWpstDnon_end
		{
			actions="dega_passenger_inside_7_leftfloorPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimtopistol_end.rtm";
			speed=1.875;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_FromPistol: AmovPpneMstpSrasWpstDnon_AmovPpneMstpSrasWrflDnon
		{
			actions="dega_passenger_inside_7_leftfloorPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimFrompistol.rtm";
			speed=2.3076921;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_FromPistol_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_FromPistol_End: AmovPpneMstpSrasWpstDnon_AmovPpneMstpSrasWrflDnon_end
		{
			actions="dega_passenger_inside_7_leftfloorActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimfrompistol_end.rtm";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			speed=2;
			leftHandIKCurve[]={0,0,0.5,1};
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Binoc: cargo_basebinoc
		{
			actions="dega_passenger_inside_7_leftfloorBinocActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim_Binoc.rtm";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			speed=-8;
			rightHandIKCurve[]={0};
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_FromBinoc",
				0.1,
				"dega_passenger_inside_7_leftfloor_Die",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Pistol_Binoc: cargo_basebinoc
		{
			actions="dega_passenger_inside_7_leftfloorBinocPistolActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol_Binoc.rtm";
			aiming="aimingRifleSlingDefault";
			aimingBody="aimingUpRifleSlingDefault";
			showHandGun=1;
			speed=-8;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol_FromBinoc",
				0.1,
				"dega_passenger_inside_7_leftfloor_Die_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Aim_ToBinoc: AmovPercMstpSrasWrflDnon_AwopPercMstpSoptWbinDnon
		{
			actions="dega_passenger_inside_7_leftfloorBinocActions";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim_ToBinoc.rtm";
			speed=1.5789469;
			leftHandIKCurve[]={0,1,0.15000001,0};
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_ToBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_ToBinoc_End: AmovPercMstpSrasWrflDnon_AwopPercMstpSoptWbinDnon_end
		{
			actions="dega_passenger_inside_7_leftfloorBinocActions";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim_ToBinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Binoc",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_FromBinoc: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWrflDnon
		{
			actions="dega_passenger_inside_7_leftfloorBinocActions";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim_frombinoc.rtm";
			speed=1.5789469;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_FromBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_FromBinoc_End: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWrflDnon_end
		{
			actions="dega_passenger_inside_7_leftfloorActions";
			aiming="aimingDefault";
			aimingBody="aimingUpDefault";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aim_frombinoc_end.rtm";
			speed=1.764706;
			leftHandIKCurve[]={0,0,0.5,1};
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Pistol_ToBinoc: AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon
		{
			actions="dega_passenger_inside_7_leftfloorBinocActions";
			showHandGun=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol_ToBinoc.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol_ToBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Pistol_ToBinoc_End: AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon_end
		{
			actions="dega_passenger_inside_7_leftfloorBinocActions";
			showHandGun=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol_ToBinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol_Binoc",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Pistol_FromBinoc: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon
		{
			actions="dega_passenger_inside_7_leftfloorBinocActions";
			showHandGun=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol_frombinoc.rtm";
			speed=1.5789469;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol_FromBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Pistol_FromBinoc_End: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon_end
		{
			actions="dega_passenger_inside_7_leftfloorActions";
			showHandGun=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimpistol_frombinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Pistol",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Idle_Unarmed: cargo_base_idle
		{
			actions="dega_passenger_inside_7_leftfloorIdleUnarmedActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7idleunarmed.rtm";
			speed=100000;
			aiming="aimingNo";
			aimingBody="aimingNo";
			weaponIK=0;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_FromPistol_End",
				0.1,
				"dega_passenger_inside_7_leftfloor_Aim_ToPistol_End",
				0.1,
				"dega_passenger_inside_7_leftfloor_Aim_Unarmed_ToBinoc",
				0.1,
				"dega_passenger_inside_7_leftfloor_Die_Pistol",
				0.1
			};
			variantsAI[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Unarmed_Idling",
				1
			};
			variantsPlayer[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Unarmed_Idling",
				1
			};
		};
		class dega_passenger_inside_7_leftfloor_Idle_Unarmed_Idling: dega_passenger_inside_7_leftfloor_Idle
		{
			variantsPlayer[]={};
			headBobStrength=0;
			soundEnabled=1;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7idleunarmed1.rtm";
			speed=-10;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Unarmed",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Unarmed_Binoc: cargo_basebinoc
		{
			actions="dega_passenger_inside_7_leftfloorBinocUnarmedActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimUnarmed_Binoc.rtm";
			aiming="aimingRifleSlingDefault";
			aimingBody="aimingUpRifleSlingDefault";
			showHandGun=0;
			speed=-8;
			InterpolateTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Unarmed_FromBinoc",
				0.1,
				"dega_passenger_inside_7_leftfloor_Die_Pistol",
				0.1
			};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Unarmed_ToBinoc: AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon
		{
			actions="dega_passenger_inside_7_leftfloorBinocUnarmedActions";
			showHandGun=0;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimUnarmed_ToBinoc.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Unarmed_ToBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Unarmed_ToBinoc_End: AmovPercMstpSrasWpstDnon_AwopPercMstpSoptWbinDnon_end
		{
			actions="dega_passenger_inside_7_leftfloorBinocUnarmedActions";
			showHandGun=0;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimUnarmed_ToBinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Unarmed_Binoc",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Unarmed_FromBinoc: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon
		{
			actions="dega_passenger_inside_7_leftfloorBinocUnarmedActions";
			showHandGun=0;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimUnarmed_frombinoc.rtm";
			speed=1.5789469;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Aim_Unarmed_FromBinoc_End",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Aim_Unarmed_FromBinoc_End: AwopPercMstpSoptWbinDnon_AmovPercMstpSrasWpstDnon_end
		{
			actions="dega_passenger_inside_7_leftfloorIdleUnarmedActions";
			showHandGun=0;
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7aimUnarmed_frombinoc_end.rtm";
			speed=1.764706;
			ConnectTo[]=
			{
				"dega_passenger_inside_7_leftfloor_Idle_Unarmed",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Die: DefaultDie
		{
			actions="dega_passenger_inside_7_leftfloorDeadActions";
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7die.rtm";
			speed=1;
			looped=0;
			terminal=1;
			ragdoll=1;
			ConnectTo[]=
			{
				"Unconscious",
				0.1
			};
			InterpolateTo[]={};
		};
		class dega_passenger_inside_7_leftfloor_Die_Pistol: dega_passenger_inside_7_leftfloor_Die
		{
			file="\dega_vehicles_MH80E\data\Anim\passenger_inside_7_leftfloor\passenger_inside_7diepistol.rtm";
			actions="dega_passenger_inside_7_leftfloorDeadPistolActions";
			showHandGun=1;
		};
	};
};