#pragma once

enum class GameState
{
	Create,
	Active,
	Passive,
	Destroy,
};

enum class WorldTag
{
	Default,
	Load,
	Title,
	Play,
	SIZE,
};

enum class LayerTag
{
	Defalut,
	BackGround,
	Map,
	Tile,
	Wall,
	Object,
	Particle,
	UI,
	SIZE,
};

enum class ObjectTag
{
	Defalut,
	Camera,
	Player,
	Monster,
	BodyBox,
	HitBox,
	Particle,
	UI,
	SIZE,
};

enum class ObjectType
{
	None,
	Actor,
	DynamicText,
	InputText,
	SIZE
};

enum class ComponentType
{
	BoxCollider2D,
	CircleCollider2D,
	SpriteRenderer2D,
	Animator2D,
	RectRenderer,
	CircleRenderer,
	LineRenderer,
	TextRenderer,
	Button,
	Script,
	FiniteStateMachine,
	Transform2D,
	Camera,
	SIZE,
};

enum class ResourceType
{
	NONE,
	Texture2D,
	Sprite2D,
	Animation2D,
	AudioClip,
	Font,
	SIZE,
};

enum class BoldType
{
	Light = 200,
	U_Light = 300,
	Medium = 400,
	U_Medium = 500,
	Heavy = 700,
	U_Heavy = 800,

	Thin = 200,
	U_Thin = 300,
	Default = 400,
	Bold = 700,
	U_Bold = 800,
};