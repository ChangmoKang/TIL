# dr_ssafy.exit

![Thumbnail](.\assets\images\icons\subway-exit.png)



빠른 출구는 **사용자에게 특정 지하철역 안에서 목적지까지 가장 빠른 출구와 길 안내를 제공하는 Capsule**입니다.



## How to use

TBD



## Which algorithm we use to find exit

TBD



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


