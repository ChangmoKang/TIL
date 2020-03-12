## Purpose of making this capsule

1. Selenium을 사용해서 원하는 data 수집해보기
   1. Thumbnail
   2. Video title
   3. Video token
2. data를 bixby 내부에 넣어서 Bixby에 랜덤으로 Learnup 영상 보여주기
3. 배포
   1. 빠르게 review를 받아서 어디를 보완해야 하는지 알기 위함
   2. 사용자의 피드백을 받아보기 위함
4. data를 AWS lambda(또는 google cloud platform)에 넣어 호출해서 사용하기
5. Device ID를 사용하여
   1. 이미 봤던 것을 체크하여 랜덤 영상에서 제외
   2. 이미 봤던 목록을 보여주는 페이지 작성
   3. Bixby에 댓글 기능을 추가하여 CRUD 구현해보기