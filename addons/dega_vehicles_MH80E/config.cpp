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
		transportSoldier = 8;	
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
			class CargoTurret_01: CargoTurret 						/// position for Firing from Vehicles
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
			class CargoTurret_02: CargoTurret 						/// position for Firing from Vehicles
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
		dega_rightgunner_heli_transport_01 = "dega_rightgunner_heli_transport_01";
		dega_leftgunner_heli_transport_01 = "dega_leftgunner_heli_transport_01";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class gunner_Heli_Transport_01;
		class dega_rightgunner_heli_transport_01: gunner_Heli_Transport_01
		{
			file="\dega_vehicles_MH80E\data\Anim\dega_rightgunner_heli_transport_01.rtm";
			speed=-30;
			interpolateTo[]=
			{
				"KIA_gunner_Heli_Transport_01",
				1
			};
		};
		class dega_leftgunner_Heli_Transport_01: gunner_Heli_Transport_01
		{
			file="\dega_vehicles_MH80E\data\Anim\dega_leftgunner_heli_transport_01.rtm";
			speed=-30;
			interpolateTo[]=
			{
				"KIA_gunner_Heli_Transport_01",
				1
			};
		};		
	};
};