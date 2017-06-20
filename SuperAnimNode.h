/* sumator.h */
#ifndef SUPER_ANIM_NODE_H
#define SUPER_ANIM_NODE_H

#include "scene/2d/node_2d.h"
#include "SuperAnimResource.h"
#include "SuperAnimSprite.h"

class SuperAnimNode : public Node2D, public SuperAnim::SuperAnimHandler {
    void OBJ_TYPE(SuperAnimNode, Node2D);

    int count;
    Color myColor;
    int mId;

    bool mIsFlipX;
    bool mIsFlipY;
    float mSpeedFactor;
    bool mIsLoop;
    AnimState mAnimState;

    //sprite replacement
    SuperAnim::IdToSuperAnimSpriteMap mReplacedSpriteMap;

    //properties to show.
    bool showStage;
    bool showAxis;

    Ref<SuperAnimData> mSamRes;

    Vector<Point2> p_points;
    Vector<Point2> p_uvs;


    void superAnimDraw();
    void superAnimUpdate(float dt);

    protected:
    static void _bind_methods();

    public:

    bool PlaySection(const String &labelName, bool isLoop = false);
    bool HasSection(const String &labelName);
    void setSpeedFactor(float newSpeedFactor);

    void Pause();
    void Resume();
    bool IsPause();
    bool IsPlaying();
    int GetCurFrame();
    int GetId();

    //set the section that is played now.
    String GetCurSectionName();
    void SetCurSectionName(String section);

    float get_width();
    float get_height();

    void set_flipx(bool value);
    bool is_flipx();

    void set_flipy(bool value);
    bool is_flipy();

    void set_loop(bool value);
    bool is_loop();

    void set_showstage(bool p_ShowStage);
    bool is_showstage() const;

    void set_showaxis(bool p_ShowAxis);
    bool is_showaxis() const;

    void set_animspeed(float value);
    float get_animspeed();

    void set_sam(const Ref<SuperAnimData>);
    Ref<SuperAnimData> get_sam() const;

    void replace_sprite(const String originalSpriteName, const String newSpriteName);
    void resume_sprite(const String originalSpriteName);

    //load the resource string and get the corresponding handle.
    void load_anim(String resPath);

    //function for handling callbacks for engine events.
    void _notification(int p_what);
        
    SuperAnimNode();
};

#endif
