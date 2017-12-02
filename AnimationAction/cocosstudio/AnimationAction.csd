<GameFile>
  <PropertyGroup Name="AnimationAction" Type="Scene" ID="95c8392f-cd89-4083-96e9-2cf509f7bd17" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="10" Speed="1.0000">
        <Timeline ActionTag="177070515" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="s101line01.png" Plist="scene101bg.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="PlistSubImage" Path="s101line02.png" Plist="scene101bg.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="10" Tween="False">
            <TextureFile Type="PlistSubImage" Path="s101line01.png" Plist="scene101bg.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="18" ctype="GameNodeObjectData">
        <Size X="1280.0000" Y="720.0000" />
        <Children>
          <AbstractNodeData Name="s101bgimg_1" ActionTag="508955799" Tag="19" IconVisible="False" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="720.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="360.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="PlistSubImage" Path="s101bgimg.png" Plist="scene101bg.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Sprite_1" ActionTag="177070515" Tag="3" IconVisible="False" TopMargin="222.0000" BottomMargin="212.0000" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="286.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="640.0000" Y="355.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4931" />
            <PreSize X="1.0000" Y="0.3972" />
            <FileData Type="PlistSubImage" Path="s101line02.png" Plist="scene101bg.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>