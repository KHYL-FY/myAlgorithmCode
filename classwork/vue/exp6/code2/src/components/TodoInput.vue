<template>
    <!-- form 表单 -->
    <form class="form-inline" @submit.prevent="onFormSubmit">
        <div class="input-group mb-2 mr-sm-2">
        <!-- 输入框的前缀 -->
        <div class="input-group-prepend">
        <div class="input-group-text">任务</div>
        </div>
        <!-- 文本输入框 -->
        <input  type="text" class="form-control" placeholder="请填写任务信息" style="width: 356px" v-model.trim="taskname"/>
        </div>
        <!-- 添加按钮 -->
        <button type="submit" class="btn btn-primary mb-2">添加新任务</button>
    </form>
</template>

<script setup>
import { ref } from 'vue'
const taskname = ref('')
const emit = defineEmits(['add'])    //自定义事件
// 表单提交的事件处理函数
const onFormSubmit = () => {
    // 1. 判断任务名称是否为空
    if (!taskname.value) return alert("任务名称不能为空！");
    // 2. 触发自定义的 add 事件，并向外界传递数据
    emit('add', taskname.value)
    // 3. 清空文本框
    taskname.value = ''
}
</script>