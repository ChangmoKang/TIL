# 빠른 출구(dr_ssafy.exit)

<div align='center'>
    <img src=".\assets\images\icons\subway-exit.png" height="400" width="400">
</div>



**빠른 출구**는 사용자에게 특정 지하철역 안에서 목적지까지 **가장 빠른 출구와 길 안내를 제공**하는 Bixby Capsule입니다.



## Team & Role

**정수원**: 팀장, 기획, 디자인, 마케팅, 프론트엔드

**강창모**: 데이터가공, 백엔드, 프론트엔드 

**이주원**: 데이터가공, 백엔드, 프론트엔드

**최현호**: 마케팅, 백엔드, 프론트엔드



## How to use

> "빠른 출구에서, **사용법 알려줘**"
> "빠른 출구에서, **강남역**에서 **CGV**로 가는 출구 알려줘"
> "빠른 출구에서, **중앙공원**으로 갈 건데 **반월당역**에서 몇 번 출구로 나가야 돼"
> "빠른 출구에서, **근처** **스타벅스**로 가려고 하는데 **서면역**에서 어디로 나가야 해"



## Example

### 1. Guide

<div align='center'>
    <img src=".\assets\readme\guide.png">
</div>

> 캡슐이 어떻게 동작하는지, 어떠한 과정을 통해 출구를 찾아내는지 알 수 있습니다.



### 2. Find_exit

> **빠른 출구**에서, **<span style="color: green">스타벅스</span>**로 갈 건데 **<span style="color: red">시청역</span>** 몇 번 출구로 나가야 해

1. **출발지를 고르는 화면**

   <div align='center'>
       <img src=".\assets\readme\exit_1.png">
   </div>

2. **도착지를 고르는 화면**

   1. (default) 정확도 순서

      <div align='center'>
          <img src=".\assets\readme\exit_2.png">
      </div>

   2. 거리 순서

      <div align='center'>
          <img src=".\assets\readme\exit_4.png">
      </div>

3. **결과 화면**

   

   <div align='center'>
       <img src=".\assets\readme\exit_3.png">
   </div>

   > 네이버 맵과 카카오 맵으로 연결하여 사용할 수 있습니다.



## File Structure

```
\---find_exit
    |   capsule.bxb
    |   README.md
    |
    +---assets
    |   \---images
    |       +---easterEgg
    |       |       avocado.png
    |       |       bmo.png
    |       |       stitch.png
    |       |       tube.png
    |       |
    |       +---guide
    |       |       result.png
    |       |       selectDestination.png
    |       |       selectStation.png
    |       |
    |       \---icons
    |               end-description.png
    |               end-map.png
    |               kakao-map.png
    |               naver-map.png
    |               red-marker.png
    |               start-description.png
    |               start-map.png
    |               subway-exit.png
    |
    +---code
    |   |   changeGuideStatus.js
    |   |   findExit.js
    |   |   getDestinationList.js
    |   |   selectStation.js
    |   |
    |   +---data
    |   |       nationalStation.js
    |   |
    |   +---easterEgg
    |   |       easterEgg.js
    |   |
    |   +---error
    |   |       updateDestinationName.js
    |   |
    |   \---function
    |           calcDistance.js
    |           kakaoKeywordSearch.js
    |           priorityPush.js
    |           transformDistance.js
    |
    +---models
    |   +---actions
    |   |   |   FindExit.model.bxb
    |   |   |   getDestinationList.model.bxb
    |   |   |   SelectStation.model.bxb
    |   |   |   Url.model.bxb
    |   |   |
    |   |   +---easterEgg
    |   |   |       easterEgg.model.bxb
    |   |   |
    |   |   +---error
    |   |   |       UpdateDestinationName.model.bxb
    |   |   |
    |   |   \---guide
    |   |           ChangeGuideStatus.model.bxb
    |   |           Guide.model.bxb
    |   |
    |   \---concepts
    |       +---easterEgg
    |       |   |   Developers.model.bxb
    |       |   |
    |       |   \---primitive
    |       |           EASTEREGGEMAIL.model.bxb
    |       |           EASTEREGGGITHUB.model.bxb
    |       |           EASTEREGGNAME.model.bxb
    |       |           EASTEREGGROLE.model.bxb
    |       |           EASTEREGGTHUMBNAIL.model.bxb
    |       |
    |       +---primitive
    |       |       ADDRESS.model.bxb
    |       |       DESTINATIONNAME.model.bxb
    |       |       EXITNUM.model.bxb
    |       |       GUIDEMETHOD.model.bxb
    |       |       GUIDESTEP.model.bxb
    |       |       LOCATION.model.bxb
    |       |       NAME.model.bxb
    |       |       PEDESTRIANDISTANCE.model.bxb
    |       |       REGIONNAME.model.bxb
    |       |       REQUIREDTIME.model.bxb
    |       |       SORT.model.bxb
    |       |       STATIONNAME.model.bxb
    |       |       STRAIGHTDISTANCE.model.bxb
    |       |       URL.model.bxb
    |       |       USERLOCATION.model.bxb
    |       |       WAYTOOFAR.model.bxb
    |       |
    |       \---structure
    |               BaseStructure.model.bxb
    |               Description.model.bxb
    |               Destination.model.bxb
    |               Result.model.bxb
    |               Speech.model.bxb
    |               Station.model.bxb
    |               UrlStructure.model.bxb
    |
    \---resources
        +---en-US
        |       capsule-info.bxb
        |       hints.bxb
        |
        \---ko-KR
            |   capsule-info.bxb
            |   endpoints.bxb
            |   hints.bxb
            |
            +---dialogs
            |       templateMacro.dialog.bxb
            |
            +---layouts
            |       layoutFirst.layout.bxb
            |       layoutGuide.layout.bxb
            |       layoutLast.layout.bxb
            |       layoutZero.layout.bxb
            |
            +---training
            |
            +---views
            |   |   first.view.bxb
            |   |   last.view.bxb
            |   |   url.view.bxb
            |   |   zero.view.bxb
            |   |
            |   +---easterEgg
            |   |       easterEgg.view.bxb
            |   |
            |   +---error
            |   |       UpdateDestinationName.view.bxb
            |   |
            |   \---guide
            |           guide.view.bxb
            |
            \---vocab
                    REGIONNAME.vocab.bxb
                    SORT.vocab.bxb
                    STATIONNAME.vocab.bxb

last updated: 2019/11/02
```


