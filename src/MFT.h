#ifndef __STRUCTS_H__

# include <iostream>
# include <vector>

namespace MFT
{
	enum eDataset
	{
		USE_DATASET_NAME,
		USE_DATASET_TITLE
	};

	enum eUnitCategory
	{
		ANGULAR_DISTANCE = 0,
		LINEAR_DISTANCE
	};

	enum eCoordSysType
	{
		METERS = 0,
		FEET,
		INCHES,
		KILOMETERS,
		CENTIMETERS,
		MILLIMETERS,
		NAUTICAL_MILES,
		MILES,
		DEGREES,
		RADIANS,
		MINUTES,
		SECONDS,
		ARCMINUTES,
		ARCSECONDS
	};

	enum eElevationType
	{
		MSL = 0,
		WGS84_GEOID,
		ELLIPSOID,
		UNDEFINED
	};

	enum eHemisphere
	{
		NORTH = 0,
		SOUTH
	};

	enum eGeoType
	{
		GEODETIC = 0,
		GEOCENTRIC
	};

	enum eSystemOriented
	{
		Z_UP_Y_FORWARD = 0
	};

	enum eCatalogType
	{
		DFAD = 0,
		FACC,
		EDCS,
		RPRFOM,
		DIS,
		FLIGHTIG,
		OTHER
	};

	enum eCycleMode
	{
		FORWARD = 0,
		BACKWARD,
		SWING
	};

	enum ePixelOrigin
	{
		LL_OPENGL_PIXELORIGIN_TYPE = 0,
		UL_DIRECTX_PIXELORIGIN_TYPE,
		LR_PIXELORIGIN_TYPE,
		UR_PIXELORIGIN_TYPE
	};

	enum eHierarchyType
	{
		ADDITIVE = 0,
		SUBSTITUTIVE,
		SPARSE_SUBSTITUTIVE
	};

	enum eTileType
	{
		GROUP = 0,
		FILE_LOD_GEOM,
		LOD_GEOM,
		FILE_GROUP,
		FILE_GEOM
	};

	enum eLocalizedType
	{
		LOCALIZED = 0,
		LOCALIZED_DEPENDENT,
		UNLOCALIZED
	};

	typedef struct s_Position
	{
		double x;
		double y;
		double z;
	} Position;

	typedef struct s_RGB
	{
		int r;
		int g;
		int b;
	} RGB;

	typedef struct s_MinMaxValue 
	{
		double Min;
		double Max;
		double Value;
	} MinMaxValue;

	typedef struct s_Ellipsoid
	{
		double SemiMajorRadius;
		double SemiMinorRadius;
		Position DatumShift;
	} Ellipsoid;

	typedef struct s_StereographicProj
	{
		std::string Description;
		std::string Source;
		double OriginLatitude;
		double OriginLongitude;
		double ScaleLatitude;
		double ScaleK0;
		bool UseScaleK0;
	} StereographicProj;

	typedef struct s_AlbersEqualAreaConicProj
	{
		std::string Description;
		std::string Source;
		double OriginLatitude;
		double OriginLongitude;
		double LowerLatitude;
		double UpperLatitude;
	} AlbersEqualAreaConicProj;

	typedef struct s_UTMProj
	{
		std::string Description;
		std::string Source;
		unsigned int Zone;
		eHemisphere Hemisphere;
	} UTMProj;

	typedef struct s_LambertConicConformalProj
	{
		std::string Description;
		std::string Source;
		double OriginLatitude;
		double OriginLongitude;
		double LowerLatitude;
		double UpperLatitude;
	} LambertConicConformalProj;

	typedef struct s_FlatEarthProj
	{
		std::string Description;
		std::string Source;
		double OriginLatitude;
		double OriginLongitude;
	} FlatEarthProj;

	typedef struct s_TrapezoidalProj
	{
		std::string Description;
		std::string Source;
		double OriginLatitude;
		double OriginLongitude;
	};

	typedef struct s_ProjectedCoordSysType
	{
		eUnitCategory UnitsCategory;
		eCoordSysType HorizontalUnitType;
		eCoordSysType VerticalUnitType;
		Position FalseOrigin;
		eElevationType VerticalDatum;
		Ellipsoid* HorizontalDatumUsed;
		StereographicProj Stereographic;
		AlbersEqualAreaConicProj AlbersEqualAreaConic;
		UTMProj UTM;
		LambertConicConformalProj LambertConicConformal;
		FlatEarthProj FlatEarth;
	} ProjectedCoordSysType;

	typedef struct s_NonProjectedCoordSysType
	{
		eUnitCategory UnitsCategory;
		eCoordSysType HorizontalUnitType;
		eCoordSysType VerticalUnitType;
		eElevationType VerticalDatum;
		Ellipsoid* HorizontalDatumUsed;
		eGeoType GeoType;
	} NonProjectedCoordSysType;

	typedef struct s_NonGeoreferencedCoordSys
	{
		eUnitCategory UnitsCategory;
		eCoordSysType HorizontalUnitType;
		eCoordSysType VerticalUnitType;
		eSystemOriented UpForwardAxis;
	} NonGeoreferencedCoordSys;

	typedef struct s_GridLevel
	{
		std::string LevelName;
		int NumColDivision;
		int NumRowDivision;
		RGB RGBColor;
	} GridLevel;

	typedef struct s_GridStructure
	{
		int NumLevels;
		int StartingLevel;
		std::vector<GridLevel> GridLevels;
	} GridStructure;

	typedef struct s_Coverage
	{
		std::string CoordSysUsed;
		Position Origin;
		Position Extent;
	} Coverage;

	typedef struct s_SwitchDistance
	{
		double value;
	} SwitchDistance;

	typedef struct s_SwitchDistanceTable
	{
		std::vector<SwitchDistance> SwitchDistances;
	} SwitchDistanceTable;

	typedef struct s_GeneralListDataset
	{
		std::string DatasetName;
		std::string DatasetTitle;
		std::string Description;
		std::string Volume;
		std::string RootPath;
		std::vector<std::string> FileNames;
	} GeneralListDataset;

	typedef struct s_CatalogAttribute
	{
		eCatalogType CatalogType;
		std::string AttributeCode;
		std::string AttributeValue;
		std::string Description;
	} CatalogAttribute;

	typedef struct s_AABB
	{
		Position Min;
		Position Max;
	} AABB;

	typedef struct s_Texture
	{
		std::string FileName;
	} Texture;

	typedef struct s_sTextures
	{
		int Count;
		int Memory;
		int FileSize;
		std::vector<Texture> Textures;
	} sTextures;

	typedef struct s_Animation
	{
		int ID;
		std::string Comment;
		std::vector<CatalogAttribute> CatalogAttributes;
		double CycleRate;
		eCycleMode CycleMode;
		int CycleCount;
	} Animation;

	typedef struct s_Dof
	{
		int ID;
		std::string Comment;
		std::vector<CatalogAttribute> CatalogAttributes;
		MinMaxValue DofValueX;
		MinMaxValue DofValueY;
		MinMaxValue DofValueZ;
		MinMaxValue DofValueRotX;
		MinMaxValue DofValueRotY;
		MinMaxValue DofValueRotZ;
	} Dof;

	typedef struct s_LightPointSystem
	{
		int ID;
		std::string Comment;
		std::vector<CatalogAttribute> CatalogAttributes;
	} LightPointSystem;

	typedef struct s_Lod
	{
		int ID;
		std::string Comment;
		std::vector<CatalogAttribute> CatalogAttributes;
		double In;
		double Out;
		double SignificantSize;
		int NumPolygons;
		std::string LOD_Category;
	} Lod;

	typedef struct s_Sound
	{
		int ID;
		std::string Comment;
		std::vector<CatalogAttribute> CatalogAttributes;
		std::string SoundUsed;
	} Sound;

	typedef struct s_SwitchState
	{
		std::string SwitchStateMask;
	} SwitchState;

	typedef struct s_Switch
	{
		int ID;
		std::string Comment;
		std::vector<CatalogAttribute> CatalogAttributes;
		std::vector<SwitchState> SwitchStates;
	} Switch;

	typedef struct s_GeneralModelComponent
	{
		int ID;
		std::string Comment;
		std::vector<CatalogAttribute> CatalogAttributes;
	} GeneralModelComponent;

	typedef struct s_LightSource
	{
		int ID;
		std::string Comment;
		std::vector<CatalogAttribute> CatalogAttributes;
	} LightSource;

	typedef struct s_sModelComponents
	{
		std::vector<Animation> Animations;
		std::vector<Dof> Dofs;
		std::vector<LightPointSystem> LightPointSystems;
		std::vector<Lod> Lods;
		std::vector<Sound> Sounds;
		std::vector<Switch> Switchs;
		std::vector<GeneralModelComponent> GeneralModelComponents;
		std::vector<LightSource> LightSources;
	} sModelComponents;

	typedef struct s_Model
	{
		std::string FileName;
		std::string Description;
		std::vector<CatalogAttribute> CatalogAttributes;
		std::string CreationTime;
		std::string ModificationTime;
		int VersionMajor;
		int VersionMinor;
		int FileSize;
		int NumPolygons;
		int NumTrianglesInHighLOD;
		AABB BoundingBox;
		sTextures Textures;
		sModelComponents ModelComponents;
	} Model;

	typedef struct s_ModeListDataset
	{
		std::string DatasetName;
		std::string DatasetTitle;
		std::string Description;
		std::string Volume;
		std::string RootPath;
		std::string MasterPaletteFile;
		std::vector<Model> Models;
	} ModelListDataset;

	typedef struct s_Row
	{
		int ID;
		std::string State;
		std::string Data;
	} Row;

	typedef struct s_StatemapLevel
	{
		int ID;
		std::string State;
		std::vector<Row> Rows;
	} StatemapLevel;

	typedef struct s_sExistenceMap
	{
		std::string Compression;
		std::vector<StatemapLevel> StatemapLevels;
	} sExistenceMap;

	typedef struct s_sGridStack
	{
		std::string GridStructureUsed;
		std::string CoverageUsed;
		std::string FileNamePattern;
		sExistenceMap ExistenceMap;
	} sGridStack;

	typedef struct s_GeneralGridDataset
	{
		std::string DatasetName;
		std::string DatasetTitle;
		std::string Description;
		std::string Volume;
		std::string RootPath;
		std::string FileFormat;
		std::string CoordSysUsed;
		sGridStack GridStack;
	} GeneralGridDataset;

	typedef struct s_sImageAttributes
	{
		int NumComponents;
		int BitsPerComponents;
		std::string ImageFormat;
	} sImageAttributes;

	typedef struct s_MaterialLayer
	{
		int Material;
		RGB CognitiveColor;
		std::string MaterialName;
		std::string StyleName;
	} MaterialLayer;

	typedef struct s_sMaterialLayerTable
	{
		std::vector<MaterialLayer> MaterialLayers;
	} sMaterialLayerTable;

	typedef struct s_ImageGridDataset
	{
		std::string DatasetName;
		std::string DatasetTitle;
		std::string Description;
		std::string Volume;
		std::string RootPath;
		std::string FileFormat;
		std::string CoordSysUsed;
		sGridStack GridStack;
		sImageAttributes ImageAttributes;
		int ImageHeight;
		int ImageWidth;
		ePixelOrigin PixelOrigin;
		sMaterialLayerTable MaterialLayerTable;
	} ImageGridDataset;

	typedef struct s_VirtualTextureDataset
	{
		std::string DatasetName;
		std::string DatasetTitle;
		std::string Description;
		std::string Volume;
		std::string FileFormat;
		std::string CoordSysUsed;
		sGridStack GridStack;
		sImageAttributes ImageAttributes;
		int NumVirtualTexels;
		int NumTileTexels;
		std::string SubstitutionTexture;
		ePixelOrigin PixelOrigin;
		sMaterialLayerTable MaterialLayerTable;
	} VirtualTextureDataset;

	typedef struct s_GeometryGridLevel
	{
		eTileType TileType;
		eLocalizedType LocalizedType;
		std::string SwitchOut_DistanceUsed;
		std::string SwitchIn_DistanceUsed;
	} GeometryGridLevel;

	typedef struct s_GeometryGridDataset
	{
		std::string DatasetName;
		std::string DatasetTitle;
		std::string Description;
		std::string Volume;
		std::string RootPath;
		std::string FileFormat;
		std::string CoordSysUsed;
		sGridStack sGridStack;
		eHierarchyType HierarchyTypes;
		std::string MasterPaletteFile;
		std::string SwitchDistanceTableUsed;
		std::vector<std::string> ModelListDatasetUsed;
		std::vector<GeomtryGridLevel> GeometryGridLevels;
	} GeometryGridDataset;

	typedef struct s_VectorGridLevel
	{
		std::string SourceLayerName;
	} VectorGridLevel;

	typedef struct s_VectorGridDataset
	{
		std::string DatasetName;
		std::string DatasetTitle;
		std::string Description;
		std::string Volume;
		std::string RootPath;
		std::string FileFormat;
		std::string CoordSysUsed;
		sGridStack GridStack;
		std::vector<VectorGridLevel> VectorGridLevels;
	} VectorGridDataset;

	typedef struct s_database
	{
		std::string SchemaCopyright;
		unsigned int VersionMajor;
		unsigned int VersionMinor;
		std::string PublicationDate;
		std::string RecipientName;
		std::string RecipientOrganization;
		std::string RecipientProject;
		std::string FeatureTagDesription;
		eDataset DatasetNameMapping;
		std::vector<Ellipsoid> Ellipsoids;
		std::vector<ProjectedCoordSysType> ProjectedCoordSysTypes;
		std::vector<NonProjectedCoordSysType> NonProjectedCoordSysTypes;
		std::vector<NonGeoreferencedCoordSys> vNonGeoreferencedCoordSys;
		std::vector<GridStructure> GridStructures;
		std::vector<Coverage> Coverages;
		std::vector<SwitchDistanceTable> SwitchDistanceTables;
		std::vector<GeneralListDataset> GeneralListDatasets;
		std::vector<ModelListDataset> ModelListDatasets;
		std::vector<GeneralGridDataset> GeneralGridDatasets;
		std::vector<ImageGridDataset> ImageGridDatasets;
		std::vector<VirtualTextureDataset> VirtualTextureDatasets;
		std::vector<GeometryGridDataset> GeometryGridDatasets;
		std::vector<VectorGridDataset> VectorGridDatasets;
	} Database;
}

#endif /* __STRUCTS_H__ */