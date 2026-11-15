<script setup>
import { ref } from 'vue'

const index = ref(1);

const left = () => {
    if (index.value > 1) index.value--;
}

const right = () => {
    if (index.value < 10) index.value++;
}
const getImage = (n) => {
    return new URL(`../assets/images/mudan${n}.jpg`, import.meta.url).href;
}
</script>

<template>
<h1>软工2541班王艺杰</h1>
    <h1>洛阳牡丹甲天下,花开时节动京城</h1>
    <div id="box">
        <img :src="getImage(index)" alt="">
        <!-- <img :src="'/images/mudan' + index + '.jpg'" alt=""> -->
        <a href="javascript:;" @click="left" v-show="index != 1">
            <img class="imgl" src="../assets/images/left.png">
        </a>
        <a href="javascript:;" @click="right" v-show="index != 10">
            <img class="imgr" src="../assets/images/right.png">
        </a>
</div> 
</template>
<style scoped>
#box {
    width: 400px;
    margin: 0 auto;
    position: relative;
}
h1 {
    text-align: center;
}
#box>img {
    width: 100%;
    height: 300px;
    /*overflow: hidden;   消除误差*/
    display: block;
    /*消除误差*/
}
a>img {
    width: 30px;
    height: 50px;
    position: absolute;
}
a>.imgl {
    left: 0;
    top: 125px;
}
a>.imgr {
    right: 0;
    top: 125px;
}
</style>